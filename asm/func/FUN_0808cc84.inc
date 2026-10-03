	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0808CCA2
	b _0808CE04
_0808CCA2:
	ldr r3, _0808CCE0 @ =0x00000282
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808CCB6
	adds r2, #5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808CD48
_0808CCB6:
	ldr r3, _0808CCE4 @ =0x00000C03
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808CCF0
	ldr r1, _0808CCE8 @ =0x00000C02
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r2, _0808CCEC @ =0x00000C0C
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc8
	movs r3, #1
	bl MainSprite_SetPose
	b _0808CD24
	.align 2, 0
_0808CCE0: .4byte 0x00000282
_0808CCE4: .4byte 0x00000C03
_0808CCE8: .4byte 0x00000C02
_0808CCEC: .4byte 0x00000C0C
_0808CCF0:
	cmp r0, #0x1e
	bne _0808CD24
	ldr r3, _0808CD3C @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808CD40 @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl MainSprite_SetPose
_0808CD24:
	ldr r0, _0808CD44 @ =0x00000C03
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0808CE04
	movs r0, #0
	strb r0, [r1]
	b _0808CE04
	.align 2, 0
_0808CD3C: .4byte 0x00000C02
_0808CD40: .4byte 0x00000C0C
_0808CD44: .4byte 0x00000C03
_0808CD48:
	ldr r2, _0808CD98 @ =0x00000283
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808CDD4
	ldr r3, _0808CD9C @ =0x000009EE
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _0808CDA0 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808CDAC
	ldr r3, _0808CDA4 @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808CDA8 @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0808CDC4
	.align 2, 0
_0808CD98: .4byte 0x00000283
_0808CD9C: .4byte 0x000009EE
_0808CDA0: .4byte 0x0000FFFF
_0808CDA4: .4byte 0x00000C02
_0808CDA8: .4byte 0x00000C0C
_0808CDAC:
	ldr r1, _0808CDCC @ =0x00000C02
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r2, _0808CDD0 @ =0x00000C0C
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc9
_0808CDC4:
	movs r3, #1
	bl MainSprite_SetPose
	b _0808CE04
	.align 2, 0
_0808CDCC: .4byte 0x00000C02
_0808CDD0: .4byte 0x00000C0C
_0808CDD4:
	ldr r3, _0808CE34 @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808CE38 @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl MainSprite_SetPose
_0808CE04:
	ldr r0, _0808CE3C @ =0x00000D99
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0808CE48
	ldr r1, _0808CE40 @ =0x00000D98
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x68
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r2, _0808CE44 @ =0x00000DA4
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc9
	movs r3, #1
	bl MainSprite_SetPose
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	b _0808CE8E
	.align 2, 0
_0808CE34: .4byte 0x00000C02
_0808CE38: .4byte 0x00000C0C
_0808CE3C: .4byte 0x00000D99
_0808CE40: .4byte 0x00000D98
_0808CE44: .4byte 0x00000DA4
_0808CE48:
	ldr r3, _0808CE78 @ =0x00000D98
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x68
	muls r1, r0, r1
	movs r2, #0xda
	lsls r2, r2, #4
	adds r0, r4, r2
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	bne _0808CE7C
	adds r0, r1, r4
	adds r3, #0xc
	adds r0, r0, r3
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetPose
	b _0808CE8E
	.align 2, 0
_0808CE78: .4byte 0x00000D98
_0808CE7C:
	adds r0, r1, r4
	ldr r1, _0808CE94 @ =0x00000DA4
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	ldrb r2, [r2]
	movs r3, #1
	bl MainSprite_SetPose
_0808CE8E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808CE94: .4byte 0x00000DA4
