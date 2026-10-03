	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08092A50 @ =0x000009EE
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0xf
	bhi _08092A7C
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bne _08092A58
	movs r3, #1
	ldr r0, _08092A54 @ =0x0000216C
	adds r1, r4, r0
	movs r2, #2
_08092A3E:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08092A3E
	b _08092A8C
	.align 2, 0
_08092A50: .4byte 0x000009EE
_08092A54: .4byte 0x0000216C
_08092A58:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bhi _08092A8C
	ldr r0, _08092A78 @ =0x00002186
	adds r1, r4, r0
	movs r2, #2
_08092A66:
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08092A66
	b _08092A8C
	.align 2, 0
_08092A78: .4byte 0x00002186
_08092A7C:
	adds r0, r4, #0
	bl FUN_0808c1cc
	cmp r0, #0
	beq _08092A8C
	adds r0, r4, #0
	bl FUN_08092744
_08092A8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
