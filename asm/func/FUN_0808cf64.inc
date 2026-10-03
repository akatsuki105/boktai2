	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r0, _0808CFA4 @ =0x030047A4
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r2, r0
	cmp r2, #0
	beq _0808CFB4
	ldr r1, _0808CFA8 @ =0xFFFF0000
	movs r2, #0
	str r2, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	ldr r1, _0808CFAC @ =0x00000A34
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r3, _0808CFB0 @ =0x00010031
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0x47
	bl MainSprite_Add
	b _0808CFE6
	.align 2, 0
_0808CFA4: .4byte 0x030047A4
_0808CFA8: .4byte 0xFFFF0000
_0808CFAC: .4byte 0x00000A34
_0808CFB0: .4byte 0x00010031
_0808CFB4:
	movs r4, #0
	movs r1, #8
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x18
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	ldr r3, _0808CFF0 @ =0x00000A34
	adds r0, r5, r3
	adds r1, r5, #0
	adds r1, #0xa0
	ldr r3, _0808CFF4 @ =0x00010031
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0x68
	bl MainSprite_Add
	ldr r3, _0808CFF8 @ =0x00000A95
	adds r0, r5, r3
	strb r4, [r0]
_0808CFE6:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808CFF0: .4byte 0x00000A34
_0808CFF4: .4byte 0x00010031
_0808CFF8: .4byte 0x00000A95
