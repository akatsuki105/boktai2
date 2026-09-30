	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0804A9D0 @ =gTextSlideshow
	str r4, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r4, #0x24]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0804A9C4
	ldr r2, _0804A9D4 @ =0x03003E78
	ldrh r1, [r2]
	strh r1, [r4, #0x26]
	ldr r0, _0804A9D8 @ =0xFFFFF1FF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	strh r0, [r2]
_0804A9C4:
	adds r0, r4, #0
	bl TextSlideshow_Start
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804A9D0: .4byte gTextSlideshow
_0804A9D4: .4byte 0x03003E78
_0804A9D8: .4byte 0xFFFFF1FF
