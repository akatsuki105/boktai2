	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r2, _0801F8A4 @ =0x085AAA5C
	movs r0, #0x39
	adds r0, r0, r3
	mov ip, r0
	adds r4, r3, #0
	adds r4, #0x38
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	mov r1, ip
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	strb r0, [r3, #7]
	mov r5, ip
	ldrb r0, [r5]
	cmp r0, #2
	bne _0801F8A8
	adds r0, r3, #0
	adds r0, #0x70
	ldrh r0, [r0]
	subs r0, #0x28
	strh r0, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x72
	ldrh r0, [r0]
	subs r0, #0x5a
	strh r0, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x74
	ldrh r0, [r0]
	subs r0, #0x28
	strh r0, [r3, #0x20]
	b _0801F8E0
	.align 2, 0
_0801F8A4: .4byte 0x085AAA5C
_0801F8A8:
	cmp r0, #0
	bne _0801F8D8
	ldrb r0, [r4]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801F8D8
	adds r0, r3, #0
	adds r0, #0x70
	ldrh r0, [r0]
	adds r0, #0x50
	strh r0, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x72
	ldrh r0, [r0]
	adds r0, #0xb4
	strh r0, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x74
	ldrh r0, [r0]
	adds r0, #0x50
	strh r0, [r3, #0x20]
	b _0801F8E0
_0801F8D8:
	ldr r0, [r3, #0x70]
	ldr r1, [r3, #0x74]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
_0801F8E0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
