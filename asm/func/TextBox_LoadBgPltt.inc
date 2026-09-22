	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _08047758 @ =0x000092B3
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	adds r1, r0, #0
	cmp r1, #0
	beq _0804775C
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	adds r2, #0x58
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0
	b _08047760
	.align 2, 0
_08047758: .4byte 0x000092B3
_0804775C:
	movs r0, #1
	rsbs r0, r0, #0
_08047760:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
