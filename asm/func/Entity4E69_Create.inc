	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080223B4 @ =0x03002B4C
	ldr r0, [r0]
	cmp r0, #0
	beq _080223B8
	movs r0, #0
	b _080223EE
	.align 2, 0
_080223B4: .4byte 0x03002B4C
_080223B8:
	movs r0, #2
	movs r1, #0xac
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080223EC
	ldr r1, _080223E4 @ =Entity4E69_Update
	ldr r2, _080223E8 @ =Entity4E69_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity4E69_Init
	cmp r0, #0
	bge _080223EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080223EE
	.align 2, 0
_080223E4: .4byte Entity4E69_Update
_080223E8: .4byte Entity4E69_Destroy
_080223EC:
	adds r0, r4, #0
_080223EE:
	pop {r4, r5}
	pop {r1}
	bx r1
