	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _08098E78 @ =0x00001464
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	ldr r2, _08098E7C @ =0x00004002
	adds r3, r1, r2
	ldrb r0, [r3]
	lsls r0, r0, #3
	ldr r4, _08098E80 @ =0x00001466
	adds r2, r1, r4
	strh r0, [r2]
	ldr r2, _08098E84 @ =0x000020A4
	adds r0, r1, r2
	adds r1, #0x60
	ldrb r2, [r3]
	adds r2, #0x42
	movs r3, #1
	bl MainSprite_SetPose
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08098E78: .4byte 0x00001464
_08098E7C: .4byte 0x00004002
_08098E80: .4byte 0x00001466
_08098E84: .4byte 0x000020A4
