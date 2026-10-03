	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	ldr r0, _0808B150 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0808B158
	cmp r6, #0
	bne _0808B1A2
	subs r0, r5, #1
	cmp r0, #2
	bhi _0808B1A2
	ldr r1, _0808B154 @ =0x00000A9B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r5, r0
	beq _0808B1A2
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0808B1A2
	.align 2, 0
_0808B150: .4byte 0x030047A4
_0808B154: .4byte 0x00000A9B
_0808B158:
	ldr r0, _0808B17C @ =0x00000A98
	adds r7, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	bne _0808B184
	ldr r1, _0808B180 @ =0x00000A99
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808B174
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0808B174:
	movs r0, #1
	strb r0, [r7]
	b _0808B1A2
	.align 2, 0
_0808B17C: .4byte 0x00000A98
_0808B180: .4byte 0x00000A99
_0808B184:
	cmp r6, #0
	beq _0808B190
	cmp r6, #1
	bne _0808B1A2
	cmp r5, #0
	bne _0808B1A2
_0808B190:
	ldr r1, _0808B1B4 @ =0x00000A9B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r5, r0
	beq _0808B1A2
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0808B1A2:
	ldr r1, _0808B1B8 @ =0x00000A9A
	adds r0, r4, r1
	strb r6, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r5, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B1B4: .4byte 0x00000A9B
_0808B1B8: .4byte 0x00000A9A
