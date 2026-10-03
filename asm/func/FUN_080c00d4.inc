	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, _080C00EC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080C00F0 @ =0x0000042E
	adds r0, r0, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _080C00F4
	movs r7, #0
	b _080C0106
	.align 2, 0
_080C00EC: .4byte 0x03002BE0
_080C00F0: .4byte 0x0000042E
_080C00F4:
	cmp r1, #3
	bhi _080C00FC
	movs r7, #1
	b _080C0106
_080C00FC:
	ldrh r0, [r0]
	subs r7, r0, #2
	subs r0, #3
	muls r0, r7, r0
	asrs r7, r0, #1
_080C0106:
	adds r0, r4, #0
	bl FUN_080bfd5c
	adds r5, r0, #0
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r6, r4, r2
	ldrh r0, [r6]
	cmp r0, r5
	beq _080C0146
	ldr r3, _080C0190 @ =0x000005A4
	adds r0, r4, r3
	ldr r2, [r0]
	cmp r2, #0
	beq _080C013E
	ldr r1, _080C0194 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	str r5, [sp]
	adds r0, r2, #0
	bl VM_ExecByID
_080C013E:
	strh r5, [r6]
	adds r0, r4, #0
	bl FUN_080bfdac
_080C0146:
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r2, #0xb6
	lsls r2, r2, #3
	adds r1, r4, r2
	muls r0, r7, r0
	ldrh r3, [r1]
	adds r2, r0, r3
	strh r2, [r1]
	ldr r0, _080C0198 @ =0x000005B2
	adds r5, r4, r0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	ldrh r3, [r5]
	cmp r0, r3
	blo _080C019C
	movs r4, #0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r3
	blo _080C018C
	adds r3, r1, #0
	adds r2, r5, #0
_080C0178:
	adds r4, #1
	ldrh r0, [r3]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r2]
	cmp r0, r1
	bhs _080C0178
_080C018C:
	adds r0, r4, #0
	b _080C019E
	.align 2, 0
_080C0190: .4byte 0x000005A4
_080C0194: .4byte 0xFFFF0000
_080C0198: .4byte 0x000005B2
_080C019C:
	movs r0, #0
_080C019E:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
