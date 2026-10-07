	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	mov ip, r1
	adds r5, r2, #0
	adds r6, r3, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r2, _08083224 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08083228
	asrs r1, r0, #0xc
	b _0808322E
	.align 2, 0
_08083224: .4byte 0x085B0A08
_08083228:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808322E:
	ldrh r0, [r4, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldrh r1, [r4, #0x2e]
	adds r1, #0xe6
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08083254
	asrs r0, r0, #0xc
	b _0808325A
_08083254:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808325A:
	ldrh r1, [r4, #0x30]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080832A4 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	str r5, [sp]
	ldr r7, _080832A8 @ =0x00000A7A
	adds r0, r4, r7
	ldrh r0, [r0]
	str r0, [sp, #4]
	ldr r1, _080832AC @ =0x00000A7C
	adds r0, r4, r1
	ldrh r0, [r0]
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	ldr r2, _080832B0 @ =0x00000A7E
	adds r0, r4, r2
	ldrh r0, [r0]
	str r0, [sp, #0x10]
	add r0, sp, #0x14
	adds r1, r3, #0
	movs r2, #0x20
	mov r3, ip
	bl Entity080cbabc_Create
	ldr r0, _080832B4 @ =0x00000367
	bl PlaySound_082406e0
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080832A4: .4byte 0xFFFF0000
_080832A8: .4byte 0x00000A7A
_080832AC: .4byte 0x00000A7C
_080832B0: .4byte 0x00000A7E
_080832B4: .4byte 0x00000367
