	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _0808491C @ =0x000003A6
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08084920 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0808488E
	b _0808499A
_0808488E:
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0xd4
	adds r6, r7, r0
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	ldr r1, _08084924 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r6]
	adds r0, r7, #0
	adds r0, #0xc0
	str r0, [r6, #0x28]
	ldr r5, _08084928 @ =0x0203B400
	ldr r4, _0808492C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	adds r3, #0x5b
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldr r2, _08084930 @ =0x000001FF
	mov ip, r2
	mov r2, ip
	ands r1, r2
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r1, r1, r2
	strh r1, [r6, #0x32]
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #0xff
	ands r0, r1
	strh r0, [r6, #0x30]
	adds r0, r7, #0
	adds r0, #0xd0
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #1
	bl Particle_SetFrame
	ldr r2, _08084934 @ =0x085B0A08
	movs r3, #0x30
	ldrsh r0, [r6, r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0x32
	ldrsh r0, [r6, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08084938
	asrs r1, r0, #0xc
	b _0808493E
	.align 2, 0
_0808491C: .4byte 0x000003A6
_08084920: .4byte 0x0000FFFF
_08084924: .4byte 0xFFFFFDFF
_08084928: .4byte 0x0203B400
_0808492C: .4byte 0x030046B8
_08084930: .4byte 0x000001FF
_08084934: .4byte 0x085B0A08
_08084938:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808493E:
	ldr r2, [r6, #0x28]
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r6, #0x18]
	ldrh r0, [r2, #2]
	strh r0, [r6, #0x1a]
	ldr r3, _08084968 @ =0x085B0A08
	ldrh r1, [r6, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0x32
	ldrsh r0, [r6, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808496C
	asrs r1, r0, #0xc
	b _08084972
	.align 2, 0
_08084968: .4byte 0x085B0A08
_0808496C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084972:
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	movs r2, #0
	strh r0, [r6, #0x1c]
	ldr r0, _080849A0 @ =FUN_080847b0
	str r0, [r6, #0x38]
	movs r0, #1
	strh r0, [r6, #0x2c]
	strh r2, [r6, #0x2e]
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _0808499A
	strh r2, [r1]
_0808499A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080849A0: .4byte FUN_080847b0
