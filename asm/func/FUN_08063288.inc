	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	mov sb, r1
	ldr r0, _08063324 @ =0x000004C7
	adds r4, r7, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _080632BC
	ldr r1, _08063328 @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, sb
	beq _080632B6
	cmp r0, #3
	bne _080632B0
	b _08063462
_080632B0:
	adds r0, r7, #0
	bl FUN_08063248
_080632B6:
	ldrb r0, [r4]
	cmp r0, #0
	bne _080632D2
_080632BC:
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r7, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _0806332C @ =0x000003DA
	adds r0, r7, r1
	strh r2, [r0]
_080632D2:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _08063344
	ldr r0, _08063330 @ =0x0203B400
	mov r8, r0
	ldr r6, _08063334 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r3, _08063338 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	movs r4, #7
	ands r0, r4
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0806333C @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #5
	lsls r0, r0, #0x10
	ldr r1, _08063340 @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	b _080633E2
	.align 2, 0
_08063324: .4byte 0x000004C7
_08063328: .4byte 0x000004C5
_0806332C: .4byte 0x000003DA
_08063330: .4byte 0x0203B400
_08063334: .4byte 0x030046B8
_08063338: .4byte 0x000003FF
_0806333C: .4byte 0xFFFF0000
_08063340: .4byte 0x0000FFFF
_08063344:
	cmp r0, #3
	bne _080633A0
	ldr r1, _0806338C @ =0x0203B400
	mov r8, r1
	ldr r6, _08063390 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r3, _08063394 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	movs r4, #7
	ands r0, r4
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08063398 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #3
	lsls r0, r0, #0x10
	ldr r1, _0806339C @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	b _080633E2
	.align 2, 0
_0806338C: .4byte 0x0203B400
_08063390: .4byte 0x030046B8
_08063394: .4byte 0x000003FF
_08063398: .4byte 0xFFFF0000
_0806339C: .4byte 0x0000FFFF
_080633A0:
	ldr r6, _08063410 @ =0x0203B400
	ldr r4, _08063414 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _08063418 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0806341C @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	movs r0, #0x1f
	ands r1, r0
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	ldr r0, _08063420 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
_080633E2:
	ldr r0, [sp, #4]
	ands r0, r5
	str r0, [sp, #4]
	ldr r2, _08063424 @ =0x000004C4
	adds r0, r7, r2
	movs r2, #0xe1
	lsls r2, r2, #4
	mov r1, sb
	mov r3, sp
	bl FUN_082467d0
	cmp r0, #0
	blt _0806345A
	ldr r1, _08063428 @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08063430
	ldr r0, _0806342C @ =0x00000191
	bl PlaySound_082406e0
	b _0806345A
	.align 2, 0
_08063410: .4byte 0x0203B400
_08063414: .4byte 0x030046B8
_08063418: .4byte 0x000003FF
_0806341C: .4byte 0xFFFF0000
_08063420: .4byte 0x0000FFFF
_08063424: .4byte 0x000004C4
_08063428: .4byte 0x000004C5
_0806342C: .4byte 0x00000191
_08063430:
	cmp r0, #2
	bne _08063450
	ldr r2, _08063448 @ =0x00000376
	adds r0, r7, r2
	ldrh r1, [r0]
	adds r1, #0xa
	strh r1, [r0]
	ldr r0, _0806344C @ =0x00000133
	bl PlaySound_082406e0
	b _0806345A
	.align 2, 0
_08063448: .4byte 0x00000376
_0806344C: .4byte 0x00000133
_08063450:
	cmp r0, #3
	bne _0806345A
	ldr r0, _08063470 @ =0x00000133
	bl PlaySound_082406e0
_0806345A:
	ldr r0, _08063474 @ =0x0000043E
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
_08063462:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063470: .4byte 0x00000133
_08063474: .4byte 0x0000043E
