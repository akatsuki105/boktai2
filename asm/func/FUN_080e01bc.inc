	push {r4, lr}
	ldr r0, _080E01F0 @ =0x0300017C
	ldr r0, [r0]
	cmp r0, #0
	bne _080E0202
	ldr r1, _080E01F4 @ =0x00000DDC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080E0200
	ldr r1, _080E01F8 @ =0x080E00B1
	ldr r2, _080E01FC @ =0x080E010D
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080e0194
	cmp r0, #0
	bge _080E0200
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080E0202
	.align 2, 0
_080E01F0: .4byte 0x0300017C
_080E01F4: .4byte 0x00000DDC
_080E01F8: .4byte 0x080E00B1
_080E01FC: .4byte 0x080E010D
_080E0200:
	adds r0, r4, #0
_080E0202:
	pop {r4}
	pop {r1}
	bx r1
