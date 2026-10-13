	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08081ab0
	adds r0, r4, #0
	bl FUN_0808175c
	adds r0, r4, #0
	bl FUN_080817ec
	adds r0, r4, #0
	bl FUN_08081c04
	adds r0, r4, #0
	bl FUN_080816a0
	ldr r1, _0808466C @ =0x03002BE0
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r0]
	ldr r1, _08084670 @ =0x03002B98
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0808466C: .4byte 0x03002BE0
_08084670: .4byte 0x03002B98
