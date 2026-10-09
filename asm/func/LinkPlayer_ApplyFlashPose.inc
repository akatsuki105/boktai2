	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08081614 @ =0x0000095C
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08081610
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08081618
_08081610:
	adds r0, r2, #0
	b _0808161E
	.align 2, 0
_08081614: .4byte 0x0000095C
_08081618:
	ldr r1, _08081624 @ =0x0000095A
	adds r0, r3, r1
	ldrh r0, [r0]
_0808161E:
	pop {r1}
	bx r1
	.align 2, 0
_08081624: .4byte 0x0000095A
