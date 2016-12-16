class CreateTabinfs < ActiveRecord::Migration[5.0]
  def change
    create_table :tabinfs do |t|
      t.text :fio
      t.text :address
      t.text :ntel
      t.string :sex
      t.date :datro
      t.text :mestoro

      t.timestamps
    end
  end
end
