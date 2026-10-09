	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080A95C0 @ =0x03002C50
	ldr r0, [r0]
	cmp r0, #0
	bne _080A95CE
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A95CC
	ldr r1, _080A95C4 @ =Entity4063_Update
	ldr r2, _080A95C8 @ =Entity4063_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity4063_Init
	cmp r0, #0
	bge _080A95CC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A95CE
	.align 2, 0
_080A95C0: .4byte 0x03002C50
_080A95C4: .4byte Entity4063_Update
_080A95C8: .4byte Entity4063_Destroy
_080A95CC:
	adds r0, r4, #0
_080A95CE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
