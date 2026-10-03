	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r2, _0808DF54 @ =0x030044E0
	ldrh r1, [r2, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _0808DEDC
	ldr r0, _0808DF58 @ =0x00000C01
	adds r7, r4, r0
	ldrb r6, [r7]
	cmp r6, #0
	bne _0808DEDC
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #1
	bls _0808DEDC
	ldr r0, _0808DF5C @ =0x0000010B
	bl PlaySound_082406e0
	ldr r2, _0808DF60 @ =0x00000C02
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r5, [r5]
	cmp r0, r5
	blt _0808DEBA
	strb r6, [r1]
_0808DEBA:
	ldr r2, _0808DF64 @ =0x00000C04
	adds r0, r4, r2
	ldr r2, [r0]
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r4, r0
	ldr r1, _0808DF68 @ =0x00000C08
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r2]
	movs r0, #8
	strb r0, [r7]
_0808DEDC:
	mov r2, r8
	ldrh r1, [r2, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808DF3E
	ldr r0, _0808DF6C @ =0x00000F41
	adds r7, r4, r0
	ldrb r6, [r7]
	cmp r6, #0
	bne _0808DF3E
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #1
	bls _0808DF3E
	ldr r0, _0808DF5C @ =0x0000010B
	bl PlaySound_082406e0
	ldr r0, _0808DF70 @ =0x00000D98
	adds r2, r4, r0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r5, [r5]
	cmp r0, r5
	blt _0808DF1C
	strb r6, [r2]
_0808DF1C:
	ldr r0, _0808DF74 @ =0x030046A0
	ldr r1, [r0]
	adds r1, #0x58
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	movs r0, #0x68
	muls r0, r2, r0
	adds r0, r4, r0
	ldr r2, _0808DF78 @ =0x00000D9C
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	movs r0, #8
	strb r0, [r7]
_0808DF3E:
	adds r0, r4, #0
	bl FUN_0808daa8
	adds r0, r4, #0
	bl FUN_0808d1a8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808DF54: .4byte 0x030044E0
_0808DF58: .4byte 0x00000C01
_0808DF5C: .4byte 0x0000010B
_0808DF60: .4byte 0x00000C02
_0808DF64: .4byte 0x00000C04
_0808DF68: .4byte 0x00000C08
_0808DF6C: .4byte 0x00000F41
_0808DF70: .4byte 0x00000D98
_0808DF74: .4byte 0x030046A0
_0808DF78: .4byte 0x00000D9C
