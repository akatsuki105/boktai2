	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0804A848 @ =gCredits
	movs r0, #0
	str r0, [r1]
	bl TextBox_Close
	ldrh r1, [r4, #0x24]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804A83E
	ldr r1, _0804A84C @ =0x03003E78
	ldrh r0, [r4, #0x26]
	strh r0, [r1]
_0804A83E:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804A848: .4byte gCredits
_0804A84C: .4byte 0x03003E78
