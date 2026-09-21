	push {r4, lr}
	mov ip, r0
	movs r0, #0x98
	lsls r0, r0, #1
	add r0, ip
	movs r1, #2
	strh r1, [r0]
	movs r1, #0x99
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	cmp r0, #0
	beq _080CBD62
	adds r4, r0, #0
	ldr r2, _080CBD14 @ =0x085B0A08
	mov r3, ip
	adds r3, #0x21
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080CBD18
	asrs r4, r0, #0xc
	b _080CBD1E
	.align 2, 0
_080CBD14: .4byte 0x085B0A08
_080CBD18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r4, r0, #0
_080CBD1E:
	mov r1, ip
	ldrh r0, [r1, #0x2c]
	adds r0, r0, r4
	strh r0, [r1, #0x2c]
	movs r0, #0x99
	lsls r0, r0, #1
	add r0, ip
	ldrh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080CBD42
	asrs r1, r0, #0xc
	b _080CBD48
_080CBD42:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CBD48:
	mov r2, ip
	ldrh r0, [r2, #0x30]
	adds r0, r0, r1
	strh r0, [r2, #0x30]
	movs r2, #0x99
	lsls r2, r2, #1
	add r2, ip
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _080CBD8E
_080CBD62:
	mov r1, ip
	adds r1, #0x21
	ldrb r0, [r1]
	adds r0, #0x80
	strb r0, [r1]
	ldrb r1, [r1]
	movs r0, #0x96
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0]
	movs r2, #0x8e
	lsls r2, r2, #1
	add r2, ip
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2, #4]
	ands r0, r1
	str r0, [r2, #4]
	mov r0, ip
	movs r1, #0
	bl EntityF41A_SetState
_080CBD8E:
	pop {r4}
	pop {r0}
	bx r0
