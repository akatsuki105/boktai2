	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _0823B92C @ =gCamera
	ldr r3, [r5]
	cmp r3, #0
	beq _0823B978
	ldrh r0, [r4]
	adds r1, r3, #0
	adds r1, #0x60
	strh r0, [r1]
	ldrh r0, [r4, #2]
	adds r2, r3, #0
	adds r2, #0x62
	strh r0, [r2]
	ldrh r2, [r4, #4]
	adds r0, r3, #0
	adds r0, #0x64
	strh r2, [r0]
	adds r0, r3, #0
	bl Camera_ApplyBounds
	ldr r5, [r5]
	mov ip, r5
	mov r1, ip
	adds r1, #0x54
	movs r0, #1
	strh r0, [r1]
	mov r1, ip
	ldrh r0, [r1, #0x1c]
	cmp r0, #0
	bne _0823B978
	ldr r2, _0823B930 @ =0x03003540
	mov r3, ip
	adds r3, #0x60
	mov r0, ip
	adds r0, #0x80
	ldrh r1, [r0]
	ldrh r3, [r3]
	adds r1, r1, r3
	strh r1, [r2]
	subs r0, #0x1e
	ldrh r0, [r0]
	strh r0, [r2, #2]
	mov r3, ip
	adds r3, #0x64
	mov r0, ip
	adds r0, #0x82
	ldrh r0, [r0]
	ldrh r3, [r3]
	adds r0, r0, r3
	strh r0, [r2, #4]
	ldr r5, _0823B934 @ =0x030047C8
	lsls r1, r1, #0x10
	asrs r4, r1, #0x11
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823B938
	asrs r0, r0, #8
	b _0823B93E
	.align 2, 0
_0823B92C: .4byte gCamera
_0823B930: .4byte 0x03003540
_0823B934: .4byte 0x030047C8
_0823B938:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823B93E:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823B950
	asrs r0, r0, #8
	b _0823B956
_0823B950:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823B956:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0823B96A
	asrs r1, r0, #8
	b _0823B970
_0823B96A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0823B970:
	subs r0, r3, r1
	strh r0, [r5, #2]
	adds r0, r3, r1
	strh r0, [r5, #4]
_0823B978:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
