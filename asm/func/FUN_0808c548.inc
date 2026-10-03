	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808C57C @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0808C5BC
	ldr r1, _0808C580 @ =0x00001BC4
	adds r0, r4, r1
	ldr r1, _0808C584 @ =0x000002DF
	bl FUN_0808ba0c
	ldr r1, _0808C588 @ =0x000009EE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _0808C590
	ldr r1, _0808C58C @ =0x00001C2C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0808C59A
	.align 2, 0
_0808C57C: .4byte 0x00003AE8
_0808C580: .4byte 0x00001BC4
_0808C584: .4byte 0x000002DF
_0808C588: .4byte 0x000009EE
_0808C58C: .4byte 0x00001C2C
_0808C590:
	ldr r1, _0808C5B4 @ =0x00001C2C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_0808C59A:
	str r1, [r0]
	ldr r0, _0808C5B8 @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0808C5D4
	movs r0, #0
	strh r0, [r1]
	b _0808C5D4
	.align 2, 0
_0808C5B4: .4byte 0x00001C2C
_0808C5B8: .4byte 0x000009EE
_0808C5BC:
	ldr r1, _0808C5F0 @ =0x00001BC4
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
	ldr r0, _0808C5F4 @ =0x00001C2C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_0808C5D4:
	ldr r1, _0808C5F8 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808C604
	ldr r1, _0808C5FC @ =0x00001C84
	adds r0, r4, r1
	ldr r1, _0808C600 @ =0x000002DF
	bl FUN_0808ba0c
	b _0808C610
	.align 2, 0
_0808C5F0: .4byte 0x00001BC4
_0808C5F4: .4byte 0x00001C2C
_0808C5F8: .4byte 0x00003AE8
_0808C5FC: .4byte 0x00001C84
_0808C600: .4byte 0x000002DF
_0808C604:
	ldr r1, _0808C618 @ =0x00001C84
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
_0808C610:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808C618: .4byte 0x00001C84
