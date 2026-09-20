	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080f8cac
	adds r0, r4, #0
	adds r0, #0x88
	bl MainSprite_Remove
	adds r0, r4, #0
	adds r0, #0xe8
	bl AuxSprite_Remove
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_0823b284
	adds r0, r4, #0
	bl FUN_080ce330
	adds r0, r4, #0
	bl FUN_080cc43c
	ldr r1, _080D8228 @ =0x03002BE0
	ldr r0, [r4, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	ldr r1, _080D822C @ =0x03002B98
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080D8228: .4byte 0x03002BE0
_080D822C: .4byte 0x03002B98
