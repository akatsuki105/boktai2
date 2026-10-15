	push {r4, r5, lr}
	bl Entity8AF6_FindEntry
	adds r5, r0, #0
	cmp r5, #0
	beq _080A59D8
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A59D8
	adds r4, r5, #0
	adds r4, #0x38
	adds r5, #0x18
	bl VM_GetValue
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0
	bl MainSprite_SetPose
_080A59D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
