	push {r4, r5, r6, lr}
	adds r2, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #5
	bls _0808C042
	b _0808C15C
_0808C042:
	lsls r0, r0, #2
	ldr r1, _0808C04C @ =_0808C050
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808C04C: .4byte _0808C050
_0808C050: @ jump table
	.4byte _0808C068 @ case 0
	.4byte _0808C068 @ case 1
	.4byte _0808C07C @ case 2
	.4byte _0808C07C @ case 3
	.4byte _0808C07C @ case 4
	.4byte _0808C068 @ case 5
_0808C068:
	ldr r1, _0808C078 @ =0x000024C4
	adds r0, r2, r1
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r2, r3
	bl MainSprite_AdvanceAnim
	b _0808C15C
	.align 2, 0
_0808C078: .4byte 0x000024C4
_0808C07C:
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r5, r2, r0
	ldr r1, _0808C0B4 @ =0x00000BA8
	adds r4, r2, r1
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0808C0B8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0808C0C0
	.align 2, 0
_0808C0B4: .4byte 0x00000BA8
_0808C0B8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0808C0C0:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0808C0E4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0808C0EC
_0808C0E4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0808C0EC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0808C124 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0808C15C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0808C128
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0808C11C
	ldrb r0, [r4, #5]
_0808C11C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0808C138
	.align 2, 0
_0808C124: .4byte 0x0000FFFF
_0808C128:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0808C138
	strh r1, [r4, #8]
_0808C138:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808C15C
	movs r0, #1
	strb r0, [r4, #7]
_0808C15C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
