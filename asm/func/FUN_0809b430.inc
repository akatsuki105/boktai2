	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _0809B460 @ =0x00000F64
	adds r4, r6, r0
	movs r5, #0x73
_0809B43A:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B43A
	movs r1, #0xb6
	lsls r1, r1, #4
	adds r0, r6, r1
	bl AuxSprite_Remove
	ldr r1, _0809B464 @ =0x00000BB8
	adds r0, r6, r1
	bl AuxSprite_Remove
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809B460: .4byte 0x00000F64
_0809B464: .4byte 0x00000BB8
