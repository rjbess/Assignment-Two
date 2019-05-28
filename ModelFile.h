// ModelFile.h
//Doxygen comments are placed .h files

// Use this file to guide you with the doxgen comments requirements for the assignment.

// Use the indentation for comments as shown so that comments don't clutter code

//---------------------------------------------------------------------------------

#ifndef MODEL_FILE_H
#define MODEL_FILE_H

//---------------------------------------------------------------------------------

#include "BlockModel.h"
#include <map>

using namespace std;

//---------------------------------------------------------------------------------


	/**
	 * @class ModelFile
	 * @brief  Manages all models and room templates
	 * 
	 * Models are constructed using Harry's block class.
	 * Room templates contain references to several models, and are used to place
	 * furniture in rooms. Models do not support collision detection.
	 * 
	 * 
	 * Template names can contain multiple words (ie with spaces).\n
	 * Case differences are ignored in template names, but not model names.\n
	 * Models are standard bdl files.\n
	 * 
	 * @author Mark Iskra
	 * @version 01 
	 * @date 26/09/2007 Mark Iskra, Started
	 *
	 * @author The monkey
	 * @version 02
	 * @date 27/09/2009 The Monkey, Added more comments
	 *
	 *
	 * @todo Let Harry know his block class is being used.
	 *
	 * @bug My program has no bugs. Well, maybe it has...
	 * @bug The program didn't make my cofee right.
	 */

class ModelFile
{
public:

		/** 
		 * @brief  Clears all loaded models and templates
		 * 
		 * This function will clear all the display lists and BDL data associated with the specific instance of this class.
		 * 
		 * @return void
		 */
	void Clear();

		/** 
		 * @brief  Loads all models listed in a text file
		 * 
		 * This function can be called multiple times with different filenames to load
		 * several sets of models.
		 * 
		 * @param  listFile - Filename of text file (lists model files)
		 * @return void
		 */
	void LoadModels(string listFile);

		/** 
		 * @brief  Loads all room templates listed in a text file
		 * 
		 * A room template is a collection of models with associated positions
		 * This function can be called multiple times with different filenames to load
		 * several sets of templates. Models used in a template must be loaded before
		 * loading the template itself.
		 * 
		 * 
		 * @param  templateFile - Filename of template file
		 * @return void
		 * @pre listFile must have contents
		 * @post will make my coffee too, dream on..
		 */
	void LoadTemplates(string templateFile);

		/** 
		 * @brief  Draws specified room template
		 * 
		 * A room template is a collection of models with associated positions
		 * It is assumed that the caller has already applied a transformation
		 * so that 0,0,0 is the minimum corner of the room
		 * 
		 * @param  templateID - ID number of template. Ranged checked
		 * @return void
		 * @pre 0,0,0 is the minimum corner of the room
		 * 
		 */
	void RenderTemplate(int templateID);

		/** 
		 * @brief  Retrieves the ID number of a template based on name
		 * 
		 * A room template is a collection of models with associated positions
		 * Returns zero if template is missing/not loaded.
		 * 
		 * @param  templateName - name of template
		 * @return void
		 */
	int GetTemplateID(string templateName);

		/**
		 * @brief  Returns a pointer to the modelfile singleton
		 * 
		 * @return ModelFile* - pointer to ModelFile singleton
		 */
	static ModelFile *GetInstance();

protected:
	ModelFile() {};
	virtual ~ModelFile() {};

		/**
		 * @brief  Returns pointer to requested model, or zero if not found.
		 * @warning Do NOT delete the pointer.
		 * 
		 * @param  modelName - Name of file model is stored in
		 * @return BlockModel* - Pointer to model
		 */
	BlockModel* ModelFile::GetModel(string modelName);

		/// Maps from model filename to model data
	map<string, BlockModel> m_models;

		/// Defines a single model used in a template
	struct TemplateObject
	{
			/// Position of model
		XYZ pos;
			/// Rotation angle
		float angle;
			/// Pointer to model
		BlockModel *model;
	};

		/// Defines a single room template
	struct Template
	{
			/// Name of template
		string name;
			/// Vector of models and their positions/rotations
		vector<TemplateObject> objects;
	};

		/// Room contents templates
	vector<Template> m_templates;
};

#endif
