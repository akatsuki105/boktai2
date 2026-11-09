	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r1, _08136A08 @ =0x00000B3A
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _08136A02
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r4, r6, r0
_081369E8:
	adds r0, r4, #0
	bl AuxSprite_Remove
	movs r1, #0x90
	lsls r1, r1, #1
	adds r4, r4, r1
	adds r5, #1
	ldr r1, _08136A08 @ =0x00000B3A
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _081369E8
_08136A02:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08136A08: .4byte 0x00000B3A
