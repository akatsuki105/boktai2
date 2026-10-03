	push {lr}
	adds r2, r0, #0
	ldr r0, _0808DA68 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0808DA80
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808DA80
	ldr r1, [r0, #0x1c]
	cmp r1, #1
	bne _0808DA80
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0808DA80
	ldr r1, _0808DA6C @ =0x00000F3D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808DA80
	ldr r1, _0808DA70 @ =0x000009FE
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0808DA80
	ldr r2, _0808DA74 @ =0x00000201
	ldr r0, _0808DA78 @ =0x030047A4
	ldr r1, _0808DA7C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _0808DA80
	movs r0, #1
	b _0808DA82
	.align 2, 0
_0808DA68: .4byte 0x030044E0
_0808DA6C: .4byte 0x00000F3D
_0808DA70: .4byte 0x000009FE
_0808DA74: .4byte 0x00000201
_0808DA78: .4byte 0x030047A4
_0808DA7C: .4byte 0x030047A0
_0808DA80:
	movs r0, #0
_0808DA82:
	pop {r1}
	bx r1
	.align 2, 0
