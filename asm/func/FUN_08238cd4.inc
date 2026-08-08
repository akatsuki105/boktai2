	push {r4, r5, lr}
	bl FUN_08238a30
	ldr r0, _08238D58 @ =0x0300082C
	movs r2, #0
	str r2, [r0]
	ldr r0, _08238D5C @ =0x03000826
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	strh r1, [r0]
	ldr r0, _08238D60 @ =0x03000824
	strh r1, [r0]
	ldr r1, _08238D64 @ =0x03004720
	ldr r0, _08238D68 @ =0x0000FFFF
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
	ldr r0, _08238D6C @ =0x03000828
	str r2, [r0]
	ldr r1, _08238D70 @ =0x030046F0
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
	ldr r0, _08238D74 @ =0x03000830
	str r2, [r0]
	ldr r0, _08238D78 @ =0x030046E0
	strh r2, [r0]
	ldr r0, _08238D7C @ =0x03004730
	strh r2, [r0]
	movs r1, #0
	ldr r5, _08238D80 @ =0x03004700
	movs r0, #1
	rsbs r0, r0, #0
	adds r4, r0, #0
_08238D36:
	lsls r0, r1, #3
	adds r3, r1, #1
	adds r1, r0, r5
	movs r2, #3
_08238D3E:
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08238D3E
	adds r1, r3, #0
	cmp r1, #3
	ble _08238D36
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08238D58: .4byte 0x0300082C
_08238D5C: .4byte 0x03000826
_08238D60: .4byte 0x03000824
_08238D64: .4byte 0x03004720
_08238D68: .4byte 0x0000FFFF
_08238D6C: .4byte 0x03000828
_08238D70: .4byte 0x030046F0
_08238D74: .4byte 0x03000830
_08238D78: .4byte 0x030046E0
_08238D7C: .4byte 0x03004730
_08238D80: .4byte 0x03004700
