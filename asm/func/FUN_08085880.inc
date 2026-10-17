	push {r4, lr}
	sub sp, #0x20
	mov ip, r0
	ldr r2, _080858B8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080858BC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080858C0 @ =0x0203B400
	adds r0, r0, r1
	movs r1, #0xff
	ldrb r4, [r0]
	ldr r2, _080858C4 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _080858C8
	asrs r0, r0, #0xc
	b _080858CE
	.align 2, 0
_080858B8: .4byte 0x030046B8
_080858BC: .4byte 0x000003FF
_080858C0: .4byte 0x0203B400
_080858C4: .4byte gSineTable
_080858C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080858CE:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _080858E6
	asrs r0, r0, #0xc
	b _080858EC
_080858E6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080858EC:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08085968 @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r1, ip
	adds r1, #0x48
	adds r0, r2, #0
	ldrh r0, [r0]
	lsls r0, r0, #2
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	mov r1, ip
	adds r1, #0x4a
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r0, ip
	adds r0, #0x4c
	ldrh r2, [r2, #4]
	lsls r2, r2, #2
	ldrh r0, [r0]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r0, sp, #0x10
	ldr r1, [r0, #4]
	ands r1, r3
	orrs r1, r2
	str r1, [r0, #4]
	movs r1, #0
	str r1, [sp, #0x18]
	add r2, sp, #0x18
	ldr r1, [r2, #4]
	ands r1, r3
	str r1, [r2, #4]
	movs r1, #3
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #8
	movs r3, #1
	bl FUN_080dbd08
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0808595E
	movs r0, #0xd3
	bl PlaySound_082406e0
_0808595E:
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08085968: .4byte 0xFFFF0000
