	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _081A0734 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A0738
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A073A
	.align 2, 0
_081A0734: .4byte 0x0000046C
_081A0738:
	movs r0, #0
_081A073A:
	cmp r0, #0
	beq _081A0792
	ldr r4, _081A07F0 @ =FUN_0819c504
	movs r3, #0x30
	ldr r7, _081A07F4 @ =0x0000046D
	adds r1, r6, r7
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A07F8 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #2
	ldr r7, _081A07FC @ =0x00000E48
	adds r1, r5, r7
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081A0800 @ =0x00000EBC
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _081A0804 @ =0x00000EB4
	adds r0, r5, r2
	strh r1, [r0]
_081A0792:
	ldr r3, _081A07F8 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A0818
	ldr r2, _081A0808 @ =FUN_0819bd2c
	movs r1, #0x22
	ldr r4, _081A07F4 @ =0x0000046D
	adds r0, r6, r4
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r7, _081A07F8 @ =0x0000046B
	adds r0, r6, r7
	strb r3, [r0]
	adds r4, #0xe6
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081A080C @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081A0810 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _081A0814 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _081A0822
	.align 2, 0
_081A07F0: .4byte FUN_0819c504
_081A07F4: .4byte 0x0000046D
_081A07F8: .4byte 0x0000046B
_081A07FC: .4byte 0x00000E48
_081A0800: .4byte 0x00000EBC
_081A0804: .4byte 0x00000EB4
_081A0808: .4byte FUN_0819bd2c
_081A080C: .4byte 0x00000469
_081A0810: .4byte 0x0000046A
_081A0814: .4byte 0x00000484
_081A0818:
	ldr r0, _081A0828 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A0822:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A0828: .4byte 0x00000484
