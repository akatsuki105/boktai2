	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r7, r1, #0
	mov r8, r2
	mov sb, r3
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x1e
	bne _0808A9CC
	movs r6, #1
	b _0808AA4C
_0808A9CC:
	ldr r0, _0808AA04 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0xdd
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _0808AA08 @ =0x000009C3
	cmp r1, r0
	ble _0808AA0C
	adds r0, #0x59
	adds r4, r5, r0
	ldrh r2, [r4]
	lsrs r0, r2, #4
	movs r1, #1
	ands r0, r1
	movs r6, #1
	cmp r0, #0
	beq _0808A9F4
	movs r6, #0
_0808A9F4:
	movs r0, #0x3f
	ands r0, r2
	cmp r0, #2
	bne _0808AA32
	movs r0, #0x99
	lsls r0, r0, #1
	b _0808AA2E
	.align 2, 0
_0808AA04: .4byte 0x030046A0
_0808AA08: .4byte 0x000009C3
_0808AA0C:
	cmp r1, #0
	ble _0808AA44
	ldr r1, _0808AA3C @ =0x00000A1C
	adds r4, r5, r1
	ldrh r2, [r4]
	lsrs r0, r2, #5
	movs r1, #1
	ands r0, r1
	movs r6, #1
	cmp r0, #0
	beq _0808AA24
	movs r6, #0
_0808AA24:
	movs r0, #0x3f
	ands r0, r2
	cmp r0, #2
	bne _0808AA32
	ldr r0, _0808AA40 @ =0x00000131
_0808AA2E:
	bl PlaySound_082406e0
_0808AA32:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0808AA4C
	.align 2, 0
_0808AA3C: .4byte 0x00000A1C
_0808AA40: .4byte 0x00000131
_0808AA44:
	movs r6, #0
	ldr r2, _0808AA74 @ =0x00000A1C
	adds r0, r5, r2
	strh r6, [r0]
_0808AA4C:
	movs r0, #0
	mov r1, r8
	mov r2, sb
	bl FUN_0808a420
	adds r3, r0, #0
	cmp r6, #0
	beq _0808AA80
	movs r2, #0
	ldr r1, _0808AA78 @ =0x030046A0
	ldr r0, _0808AA7C @ =0xFFFFD000
	adds r4, r0, #0
_0808AA64:
	adds r0, r2, #3
	orrs r0, r4
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #0xb
	ble _0808AA64
	b _0808AB32
	.align 2, 0
_0808AA74: .4byte 0x00000A1C
_0808AA78: .4byte 0x030046A0
_0808AA7C: .4byte 0xFFFFD000
_0808AA80:
	cmp r7, #1
	bne _0808AA8C
	ldr r2, _0808AA88 @ =0x0000029F
	b _0808AAE2
	.align 2, 0
_0808AA88: .4byte 0x0000029F
_0808AA8C:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x10
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0808AAD8
	ldr r2, _0808AAD0 @ =0x00000A04
	adds r0, r5, r2
	ldrh r0, [r0]
	ldr r2, _0808AAD4 @ =0x0000029F
	cmp r0, #0x24
	bls _0808AAB6
	subs r2, #0xa4
	cmp r0, #0x2c
	bls _0808AAB6
	cmp r0, #0x34
	bhi _0808AAB6
	subs r2, #0x84
_0808AAB6:
	ldr r4, _0808AAD0 @ =0x00000A04
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0808AAE2
	movs r0, #0
	strh r0, [r1]
	b _0808AAE2
	.align 2, 0
_0808AAD0: .4byte 0x00000A04
_0808AAD4: .4byte 0x0000029F
_0808AAD8:
	ldr r0, _0808AB80 @ =0x00000A04
	adds r1, r5, r0
	movs r0, #0x34
	strh r0, [r1]
	ldr r2, _0808AB84 @ =0x00000177
_0808AAE2:
	ldr r1, _0808AB88 @ =0x03004404
	ldrh r0, [r1]
	cmp r0, r2
	beq _0808AAEC
	strh r2, [r1]
_0808AAEC:
	ldr r0, _0808AB8C @ =0x030046A0
	ldr r1, [r0]
	ldr r2, _0808AB90 @ =0x00000942
	adds r1, r1, r2
	movs r2, #0
	ldrsh r4, [r1, r2]
	ldr r2, _0808AB94 @ =0x0000D05C
	adds r1, r2, #0
	strh r1, [r3]
	adds r3, #2
	movs r2, #0
	adds r1, r0, #0
	cmp r2, r4
	bge _0808AB1A
	ldr r2, _0808AB98 @ =0x0000D05D
	adds r0, r2, #0
	adds r2, r4, #0
_0808AB0E:
	strh r0, [r3]
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bne _0808AB0E
	adds r2, r4, #0
_0808AB1A:
	cmp r2, #9
	bgt _0808AB2C
	ldr r4, _0808AB9C @ =0x0000D05E
	adds r0, r4, #0
_0808AB22:
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #9
	ble _0808AB22
_0808AB2C:
	ldr r2, _0808ABA0 @ =0x0000D05F
	adds r0, r2, #0
	strh r0, [r3]
_0808AB32:
	movs r4, #0x9e
	lsls r4, r4, #4
	adds r0, r5, r4
	ldr r0, [r0]
	ldr r2, _0808ABA4 @ =0x0000038E
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #0xb2
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, #0
	ble _0808ABAC
	movs r0, #0
	movs r1, #0xf
	movs r2, #0x11
	bl FUN_0808a420
	adds r3, r0, #0
	movs r2, #0
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r1, r0, #0
_0808AB66:
	adds r0, r2, #0
	adds r0, #0x3b
	orrs r0, r1
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #4
	ble _0808AB66
	ldr r2, _0808ABA8 @ =0x00000A96
	adds r1, r5, r2
	movs r0, #1
	b _0808ABDA
	.align 2, 0
_0808AB80: .4byte 0x00000A04
_0808AB84: .4byte 0x00000177
_0808AB88: .4byte 0x03004404
_0808AB8C: .4byte 0x030046A0
_0808AB90: .4byte 0x00000942
_0808AB94: .4byte 0x0000D05C
_0808AB98: .4byte 0x0000D05D
_0808AB9C: .4byte 0x0000D05E
_0808ABA0: .4byte 0x0000D05F
_0808ABA4: .4byte 0x0000038E
_0808ABA8: .4byte 0x00000A96
_0808ABAC:
	ldr r4, _0808ABE8 @ =0x00000A96
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808ABDC
	movs r0, #0
	movs r1, #0xf
	movs r2, #0x11
	bl FUN_0808a420
	adds r3, r0, #0
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r1, #0
	movs r2, #4
_0808ABCA:
	strh r0, [r3]
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bge _0808ABCA
	ldr r2, _0808ABE8 @ =0x00000A96
	adds r1, r5, r2
	movs r0, #0
_0808ABDA:
	strb r0, [r1]
_0808ABDC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808ABE8: .4byte 0x00000A96
