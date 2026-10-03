	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, _0808B3EC @ =0x00003AE6
	adds r4, r4, r0
	ldrb r4, [r4]
	cmp r4, #0
	bne _0808B3FC
	ldr r2, _0808B3F0 @ =0x0000F023
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x77
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x9a
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _0808B3F4 @ =0x030046A0
	ldr r0, [r5]
	movs r3, #0x91
	lsls r3, r3, #4
	adds r2, r0, r3
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r1, _0808B3F8 @ =0x0000270F
	cmp r0, r1
	ble _0808B3E2
	strh r1, [r2]
_0808B3E2:
	ldr r0, [r5]
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	b _0808B43E
	.align 2, 0
_0808B3EC: .4byte 0x00003AE6
_0808B3F0: .4byte 0x0000F023
_0808B3F4: .4byte 0x030046A0
_0808B3F8: .4byte 0x0000270F
_0808B3FC:
	cmp r4, #1
	bne _0808B45C
	ldr r2, _0808B450 @ =0x0000F025
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x79
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x6b
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _0808B454 @ =0x030046A0
	ldr r0, [r5]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r1, r0, r3
	ldr r0, [r1]
	ldr r2, _0808B458 @ =0x0000270F
	cmp r0, r2
	ble _0808B438
	str r2, [r1]
_0808B438:
	ldr r0, [r5]
	adds r0, r0, r3
	ldr r0, [r0]
_0808B43E:
	movs r1, #0xfa
	lsls r1, r1, #2
	str r4, [sp]
	movs r2, #0x17
	movs r3, #1
	bl FUN_0808b30c
	b _0808B4AA
	.align 2, 0
_0808B450: .4byte 0x0000F025
_0808B454: .4byte 0x030046A0
_0808B458: .4byte 0x0000270F
_0808B45C:
	ldr r2, _0808B4B4 @ =0x0000F0B9
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #0x98
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x99
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x20
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r4, _0808B4B8 @ =0x030046A0
	ldr r0, [r4]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r1, r0, r3
	ldr r0, [r1]
	ldr r2, _0808B4BC @ =0x0000270F
	cmp r0, r2
	ble _0808B494
	str r2, [r1]
_0808B494:
	ldr r0, [r4]
	adds r0, r0, r3
	ldr r0, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	movs r2, #0
	str r2, [sp]
	movs r2, #0x17
	movs r3, #1
	bl FUN_0808b30c
_0808B4AA:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B4B4: .4byte 0x0000F0B9
_0808B4B8: .4byte 0x030046A0
_0808B4BC: .4byte 0x0000270F
