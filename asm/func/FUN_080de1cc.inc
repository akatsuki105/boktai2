	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r6, r1, #6
	cmp r6, #0
	beq _080DE1E2
	cmp r6, #2
	bne _080DE1FC
_080DE1E2:
	ldr r1, _080DE1F4 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	ldr r1, _080DE1F8 @ =0x0000FFE2
	orrs r0, r1
	b _080DE210
	.align 2, 0
_080DE1F4: .4byte 0xFFFF0000
_080DE1F8: .4byte 0x0000FFE2
_080DE1FC:
	ldr r2, _080DE23C @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	ldr r1, _080DE240 @ =0x0000FFE2
	orrs r0, r1
	adds r1, #0x1d
	ands r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r2
_080DE210:
	str r0, [sp, #4]
	adds r4, #0x1c
	mov r5, sp
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0xa
	movs r3, #4
	bl FUN_081ee07c
	adds r7, r4, #0
	cmp r6, #0
	beq _080DE22C
	cmp r6, #2
	bne _080DE248
_080DE22C:
	movs r1, #0
	mov r0, sp
	strh r1, [r0]
	movs r0, #0xf
	strh r0, [r5, #2]
	ldr r0, _080DE244 @ =0x0000FFF1
	strh r0, [r5, #4]
	b _080DE256
	.align 2, 0
_080DE23C: .4byte 0xFFFF0000
_080DE240: .4byte 0x0000FFE2
_080DE244: .4byte 0x0000FFF1
_080DE248:
	movs r2, #0
	ldr r1, _080DE27C @ =0x0000FFF1
	mov r0, sp
	strh r1, [r0]
	movs r0, #0xf
	strh r0, [r5, #2]
	strh r2, [r5, #4]
_080DE256:
	mov r4, sp
	adds r0, r7, #0
	mov r1, sp
	movs r2, #0xa
	movs r3, #4
	bl FUN_081ee07c
	cmp r6, #0
	beq _080DE26C
	cmp r6, #2
	bne _080DE280
_080DE26C:
	movs r0, #0
	mov r1, sp
	strh r0, [r1]
	movs r0, #0xf
	strh r0, [r4, #2]
	strh r0, [r4, #4]
	b _080DE28C
	.align 2, 0
_080DE27C: .4byte 0x0000FFF1
_080DE280:
	movs r2, #0
	movs r1, #0xf
	mov r0, sp
	strh r1, [r0]
	strh r1, [r4, #2]
	strh r2, [r4, #4]
_080DE28C:
	mov r4, sp
	adds r0, r7, #0
	mov r1, sp
	movs r2, #0xa
	movs r3, #4
	bl FUN_081ee07c
	cmp r6, #0
	beq _080DE2A2
	cmp r6, #2
	bne _080DE2B0
_080DE2A2:
	movs r0, #0
	mov r1, sp
	strh r0, [r1]
	strh r0, [r4, #2]
	movs r0, #0x1e
	strh r0, [r4, #4]
	b _080DE2BC
_080DE2B0:
	movs r2, #0
	movs r1, #0x1e
	mov r0, sp
	strh r1, [r0]
	strh r2, [r4, #2]
	strh r2, [r4, #4]
_080DE2BC:
	mov r4, sp
	adds r0, r7, #0
	mov r1, sp
	movs r2, #0xa
	movs r3, #4
	bl FUN_081ee07c
	cmp r6, #0
	beq _080DE2D2
	cmp r6, #2
	bne _080DE2E4
_080DE2D2:
	movs r0, #0
	mov r1, sp
	strh r0, [r1]
	ldr r0, _080DE2E0 @ =0x0000FFF1
	strh r0, [r4, #2]
	strh r0, [r4, #4]
	b _080DE2F0
	.align 2, 0
_080DE2E0: .4byte 0x0000FFF1
_080DE2E4:
	movs r2, #0
	ldr r1, _080DE318 @ =0x0000FFF1
	mov r0, sp
	strh r1, [r0]
	strh r1, [r4, #2]
	strh r2, [r4, #4]
_080DE2F0:
	mov r4, sp
	adds r0, r7, #0
	mov r1, sp
	movs r2, #0xa
	movs r3, #4
	bl FUN_081ee07c
	cmp r6, #0
	beq _080DE306
	cmp r6, #2
	bne _080DE31C
_080DE306:
	movs r1, #0
	mov r0, sp
	strh r1, [r0]
	ldr r0, _080DE318 @ =0x0000FFF1
	strh r0, [r4, #2]
	movs r0, #0xf
	strh r0, [r4, #4]
	b _080DE32A
	.align 2, 0
_080DE318: .4byte 0x0000FFF1
_080DE31C:
	movs r2, #0
	movs r1, #0xf
	mov r0, sp
	strh r1, [r0]
	ldr r0, _080DE340 @ =0x0000FFF1
	strh r0, [r4, #2]
	strh r2, [r4, #4]
_080DE32A:
	adds r0, r7, #0
	mov r1, sp
	movs r2, #0xa
	movs r3, #4
	bl FUN_081ee07c
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DE340: .4byte 0x0000FFF1
