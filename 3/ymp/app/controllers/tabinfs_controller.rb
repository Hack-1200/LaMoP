class TabinfsController < ApplicationController
  before_action :set_tabinf, only: [:show, :edit, :update, :destroy]

  # GET /tabinfs
  # GET /tabinfs.json
  def index
    @tabinfs = Tabinf.all
  end

  # GET /tabinfs/1
  # GET /tabinfs/1.json
  def show
  end


  # GET /tabinfs/new
  def new
    @tabinf = Tabinf.new
  end

  # GET /tabinfs/1/edit
  def edit
  end

  # POST /tabinfs
  # POST /tabinfs.json
  def create
    @tabinf = Tabinf.new(tabinf_params)

    respond_to do |format|
      if @tabinf.save
        format.html { redirect_to @tabinf, notice: 'Tabinf was successfully created.' }
        format.json { render :show, status: :created, location: @tabinf }
      else
        format.html { render :new }
        format.json { render json: @tabinf.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /tabinfs/1
  # PATCH/PUT /tabinfs/1.json
  def update
    respond_to do |format|
      if @tabinf.update(tabinf_params)
        format.html { redirect_to @tabinf, notice: 'Tabinf was successfully updated.' }
        format.json { render :show, status: :ok, location: @tabinf }
      else
        format.html { render :edit }
        format.json { render json: @tabinf.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /tabinfs/1
  # DELETE /tabinfs/1.json
  def destroy
    @tabinf.destroy
    respond_to do |format|
      format.html { redirect_to tabinfs_url, notice: 'Tabinf was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_tabinf
      @tabinf = Tabinf.find(params[:id])
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def tabinf_params
      params.require(:tabinf).permit(:fio, :address, :ntel, :sex, :datro, :mestoro)
    end
end
