	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	mov sb, r1
	adds r5, r2, #0
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _081D65C8
	adds r0, r4, #0
	bl Hitbox_ApplyDamage
	adds r0, r4, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, sb
	adds r0, #0x44
	strh r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	adds r0, #0x96
	ldrh r2, [r0]
	subs r6, r1, r2
	adds r1, r0, #0
	cmp r6, #0
	bge _081D651C
	adds r6, r6, r2
	b _081D651E
_081D651C:
	adds r6, r2, #0
_081D651E:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r7, r5, r3
	ldrh r0, [r7]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r4, #0
	mov r8, r4
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081D653A
	mov r0, r8
	strh r0, [r7]
_081D653A:
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r2, #0
	ldrsh r1, [r7, r2]
	movs r3, #0xa1
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r4, #0
	ldrsh r2, [r2, r4]
	ldr r4, _081D65D8 @ =0x00000147
	adds r3, r5, r4
	ldrb r3, [r3]
	mov r4, r8
	str r4, [sp]
	bl FUN_0809c344
	add r4, sp, #0xc
	mov r0, r8
	str r0, [sp, #8]
	add r0, sp, #8
	adds r1, r4, #0
	ldr r2, _081D65DC @ =0x05000002
	bl CpuSet
	adds r3, r5, #0
	adds r3, #0x1c
	str r4, [sp]
	movs r4, #1
	str r4, [sp, #4]
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0805fe7c
	ldr r2, _081D65E0 @ =0x00000153
	adds r1, r5, r2
	movs r0, #3
	strb r0, [r1]
	ldr r3, _081D65E4 @ =0x00000157
	adds r1, r5, r3
	movs r0, #0xa
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0x9c
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_081d65e8
	adds r0, r5, #0
	bl FUN_081d6bc0
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #0
	bgt _081D65C8
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #4
	strh r0, [r1]
	movs r3, #0xab
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r4, [r0]
_081D65C8:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D65D8: .4byte 0x00000147
_081D65DC: .4byte 0x05000002
_081D65E0: .4byte 0x00000153
_081D65E4: .4byte 0x00000157
