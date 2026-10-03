	push {r4, r5, lr}
	adds r3, r0, #0
	cmp r1, #1
	bne _0808AC58
	movs r4, #0x1f
	ldr r1, _0808AC30 @ =0x00000A1E
	adds r0, r3, r1
	movs r5, #0
	ldrsh r2, [r0, r5]
	ldr r1, _0808AC34 @ =0x030046A0
	ldr r0, [r1]
	movs r5, #0xae
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	adds r5, r1, #0
	cmp r2, r0
	bge _0808AC3C
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r0, r3, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x12
	movs r0, #1
	ands r1, r0
	ldr r2, _0808AC38 @ =0x00007FFF
	cmp r1, #0
	beq _0808AC7C
_0808AC2A:
	movs r2, #0xf8
	lsls r2, r2, #2
	b _0808AC7C
	.align 2, 0
_0808AC30: .4byte 0x00000A1E
_0808AC34: .4byte 0x030046A0
_0808AC38: .4byte 0x00007FFF
_0808AC3C:
	ldr r0, _0808AC50 @ =0x00000A22
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808AC2A
	ldr r2, _0808AC54 @ =0x00007FFF
	subs r0, #1
	strh r0, [r1]
	b _0808AC7C
	.align 2, 0
_0808AC50: .4byte 0x00000A22
_0808AC54: .4byte 0x00007FFF
_0808AC58:
	ldr r4, _0808AC6C @ =0x000039CE
	ldr r5, _0808AC70 @ =0x00000A22
	adds r1, r3, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808AC78
	ldr r2, _0808AC74 @ =0x00007FFF
	subs r0, #1
	strh r0, [r1]
	b _0808AC7A
	.align 2, 0
_0808AC6C: .4byte 0x000039CE
_0808AC70: .4byte 0x00000A22
_0808AC74: .4byte 0x00007FFF
_0808AC78:
	movs r2, #0x1f
_0808AC7A:
	ldr r5, _0808ACAC @ =0x030046A0
_0808AC7C:
	ldr r1, _0808ACB0 @ =0x0300440C
	ldrh r0, [r1]
	cmp r0, r4
	beq _0808AC86
	strh r4, [r1]
_0808AC86:
	subs r1, #2
	ldrh r0, [r1]
	cmp r0, r2
	beq _0808AC90
	strh r2, [r1]
_0808AC90:
	ldr r4, [r5]
	movs r0, #0xae
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r1, [r2]
	ldr r5, _0808ACB4 @ =0x00000A1E
	adds r0, r3, r5
	strh r1, [r0]
	ldr r3, [r2]
	cmp r3, #0
	bgt _0808ACB8
	movs r5, #0
	b _0808ACDC
	.align 2, 0
_0808ACAC: .4byte 0x030046A0
_0808ACB0: .4byte 0x0300440C
_0808ACB4: .4byte 0x00000A1E
_0808ACB8:
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #1
	ble _0808ACDA
	movs r1, #0x4f
	subs r0, r3, #1
	muls r0, r1, r0
	subs r1, r2, #1
	bl Div
	adds r4, r0, #1
	asrs r5, r4, #3
	lsls r0, r5, #3
	subs r4, r4, r0
	b _0808ACDE
_0808ACDA:
	movs r5, #0xa
_0808ACDC:
	movs r4, #0
_0808ACDE:
	movs r0, #0
	movs r1, #0x1d
	movs r2, #1
	bl FUN_0808a420
	adds r2, r0, #0
	ldr r1, _0808AD4C @ =0x0000D08C
	adds r0, r1, #0
	strh r0, [r2]
	subs r2, #2
	subs r1, #1
	adds r0, r1, #0
	strh r0, [r2]
	subs r2, #2
	subs r1, #1
	adds r0, r1, #0
	strh r0, [r2]
	subs r2, #2
	movs r3, #0
	cmp r3, r5
	bge _0808AD1A
	subs r1, #1
	adds r0, r1, #0
	adds r3, r5, #0
_0808AD0E:
	strh r0, [r2]
	subs r2, #2
	subs r3, #1
	cmp r3, #0
	bne _0808AD0E
	adds r3, r5, #0
_0808AD1A:
	cmp r4, #0
	beq _0808AD2E
	adds r0, r4, #0
	adds r0, #0x81
	ldr r4, _0808AD50 @ =0xFFFFD000
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
_0808AD2E:
	cmp r3, #9
	bgt _0808AD40
	ldr r5, _0808AD54 @ =0x0000D081
	adds r0, r5, #0
_0808AD36:
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
	cmp r3, #9
	ble _0808AD36
_0808AD40:
	ldr r1, _0808AD58 @ =0x0000D080
	adds r0, r1, #0
	strh r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808AD4C: .4byte 0x0000D08C
_0808AD50: .4byte 0xFFFFD000
_0808AD54: .4byte 0x0000D081
_0808AD58: .4byte 0x0000D080
