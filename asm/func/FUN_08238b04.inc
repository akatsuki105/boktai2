	push {r4, r5, lr}
	ldr r1, _08238B90 @ =0x030046C4
	movs r0, #1
	str r0, [r1]
	bl FUN_082389c8
	ldr r0, _08238B94 @ =0x0300082C
	movs r2, #0
	str r2, [r0]
	ldr r0, _08238B98 @ =0x03000826
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	strh r1, [r0]
	ldr r0, _08238B9C @ =0x03000824
	strh r1, [r0]
	ldr r1, _08238BA0 @ =0x03004720
	ldr r0, _08238BA4 @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	strh r0, [r1, #8]
	strh r0, [r1, #0xa]
	strh r0, [r1, #0xc]
	strh r0, [r1, #0xe]
	ldr r0, _08238BA8 @ =0x03000828
	str r2, [r0]
	ldr r1, _08238BAC @ =0x030046F0
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	strh r0, [r1, #8]
	strh r0, [r1, #0xa]
	strh r0, [r1, #0xc]
	strh r0, [r1, #0xe]
	ldr r0, _08238BB0 @ =0x03000830
	str r2, [r0]
	ldr r0, _08238BB4 @ =0x030046E0
	strh r2, [r0]
	ldr r0, _08238BB8 @ =0x03004730
	strh r2, [r0]
	movs r1, #0
	ldr r5, _08238BBC @ =0x03004700
	movs r0, #1
	rsbs r0, r0, #0
	adds r4, r0, #0
_08238B6C:
	lsls r0, r1, #3
	adds r3, r1, #1
	adds r1, r0, r5
	movs r2, #3
_08238B74:
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08238B74
	adds r1, r3, #0
	cmp r1, #3
	ble _08238B6C
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08238B90: .4byte 0x030046C4
_08238B94: .4byte 0x0300082C
_08238B98: .4byte 0x03000826
_08238B9C: .4byte 0x03000824
_08238BA0: .4byte 0x03004720
_08238BA4: .4byte 0x0000FFFF
_08238BA8: .4byte 0x03000828
_08238BAC: .4byte 0x030046F0
_08238BB0: .4byte 0x03000830
_08238BB4: .4byte 0x030046E0
_08238BB8: .4byte 0x03004730
_08238BBC: .4byte 0x03004700
