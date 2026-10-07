	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808E040 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0808E0D6
	ldr r1, _0808E044 @ =0x000009FE
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0808E0D6
	adds r0, r4, #0
	bl FUN_0808de70
	ldr r2, _0808E048 @ =0x00000A16
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0x3f
	bhi _0808E04C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a610
	b _0808E058
	.align 2, 0
_0808E040: .4byte 0x030044BC
_0808E044: .4byte 0x000009FE
_0808E048: .4byte 0x00000A16
_0808E04C:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl EntityCC28_DrawHP
_0808E058:
	ldr r0, _0808E084 @ =0x00000A16
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _0808E06E
	movs r0, #0
	strh r0, [r1]
_0808E06E:
	ldr r0, _0808E088 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0808E090
	ldr r1, _0808E08C @ =FUN_0808dfcc
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0808E0D6
	.align 2, 0
_0808E084: .4byte 0x00000A16
_0808E088: .4byte 0x030044E0
_0808E08C: .4byte FUN_0808dfcc
_0808E090:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0808E0D6
	bl FUN_08050dac
	ldr r2, _0808E0BC @ =0x000009F9
	adds r1, r4, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808E0C4
	ldr r1, _0808E0C0 @ =0x00000A34
	adds r0, r4, r1
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0x46
	movs r3, #1
	bl MainSprite_SetPose
	b _0808E0D6
	.align 2, 0
_0808E0BC: .4byte 0x000009F9
_0808E0C0: .4byte 0x00000A34
_0808E0C4:
	ldr r1, _0808E0DC @ =0x00000A34
	adds r0, r4, r1
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0x47
	movs r3, #1
	bl MainSprite_SetPose
_0808E0D6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E0DC: .4byte 0x00000A34
