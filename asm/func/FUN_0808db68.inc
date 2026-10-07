	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl EntityCC28_DrawHP
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #2
	bl EntityCC28_DrawEne
	ldr r0, _0808DBAC @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0808DBB8
	ldr r1, _0808DBB0 @ =0x00000C01
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808DBB8
	ldr r2, _0808DBB4 @ =0x00000F41
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808DBB8
	adds r0, r4, #0
	bl FUN_0808d9c8
	b _0808DCA4
	.align 2, 0
_0808DBAC: .4byte 0x030044E0
_0808DBB0: .4byte 0x00000C01
_0808DBB4: .4byte 0x00000F41
_0808DBB8:
	ldr r0, _0808DBF8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808DC42
	ldr r0, _0808DBFC @ =0x00000C01
	adds r7, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	bne _0808DC42
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r6, r4, r1
	ldrb r0, [r6]
	cmp r0, #1
	bls _0808DC42
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r1, _0808DC00 @ =0x00000285
	adds r0, r0, r1
	ldrb r5, [r0]
	cmp r5, #0
	beq _0808DC04
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0808DC42
	.align 2, 0
_0808DBF8: .4byte 0x030044E0
_0808DBFC: .4byte 0x00000C01
_0808DC00: .4byte 0x00000285
_0808DC04:
	ldr r0, _0808DCB8 @ =0x0000010B
	bl PlaySound_082406e0
	ldr r2, _0808DCBC @ =0x00000C02
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r6, [r6]
	cmp r0, r6
	blt _0808DC20
	strb r5, [r1]
_0808DC20:
	ldr r2, _0808DCC0 @ =0x00000C04
	adds r0, r4, r2
	ldr r2, [r0]
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r4, r0
	ldr r1, _0808DCC4 @ =0x00000C08
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r2]
	movs r0, #8
	strb r0, [r7]
_0808DC42:
	ldr r0, _0808DCC8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808DCA4
	ldr r2, _0808DCCC @ =0x00000F41
	adds r7, r4, r2
	ldrb r6, [r7]
	cmp r6, #0
	bne _0808DCA4
	movs r0, #0xf4
	lsls r0, r0, #4
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #1
	bls _0808DCA4
	ldr r0, _0808DCB8 @ =0x0000010B
	bl PlaySound_082406e0
	ldr r1, _0808DCD0 @ =0x00000D98
	adds r2, r4, r1
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r5, [r5]
	cmp r0, r5
	blt _0808DC82
	strb r6, [r2]
_0808DC82:
	ldr r0, _0808DCD4 @ =0x030046A0
	ldr r1, [r0]
	adds r1, #0x58
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	movs r0, #0x68
	muls r0, r2, r0
	adds r0, r4, r0
	ldr r2, _0808DCD8 @ =0x00000D9C
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	movs r0, #8
	strb r0, [r7]
_0808DCA4:
	adds r0, r4, #0
	bl FUN_0808daa8
	adds r0, r4, #0
	bl FUN_0808d1a8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808DCB8: .4byte 0x0000010B
_0808DCBC: .4byte 0x00000C02
_0808DCC0: .4byte 0x00000C04
_0808DCC4: .4byte 0x00000C08
_0808DCC8: .4byte 0x030044E0
_0808DCCC: .4byte 0x00000F41
_0808DCD0: .4byte 0x00000D98
_0808DCD4: .4byte 0x030046A0
_0808DCD8: .4byte 0x00000D9C
