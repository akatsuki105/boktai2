	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _08216508 @ =0x00000E8C
	adds r0, r0, r6
	mov r8, r0
	ldr r1, _0821650C @ =0x000012B0
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #1
	beq _08216550
	cmp r0, #1
	bgt _08216510
	cmp r0, #0
	beq _08216516
	b _082165CE
	.align 2, 0
_08216508: .4byte 0x00000E8C
_0821650C: .4byte 0x000012B0
_08216510:
	cmp r0, #2
	beq _0821658C
	b _082165CE
_08216516:
	ldr r7, _08216548 @ =0x085AFA30
	movs r0, #0x96
	lsls r0, r0, #5
	adds r5, r6, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sound_08240960
	cmp r0, #0
	beq _08216542
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sound_08240740
_08216542:
	ldr r0, _0821654C @ =0x000012BA
	b _082165B8
	.align 2, 0
_08216548: .4byte 0x085AFA30
_0821654C: .4byte 0x000012BA
_08216550:
	ldr r7, _08216580 @ =0x085AFAEE
	ldr r0, _08216584 @ =0x000012C2
	adds r5, r6, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sound_08240960
	cmp r0, #0
	beq _0821657A
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sound_08240740
_0821657A:
	ldr r0, _08216588 @ =0x000012BC
	b _082165B8
	.align 2, 0
_08216580: .4byte 0x085AFAEE
_08216584: .4byte 0x000012C2
_08216588: .4byte 0x000012BC
_0821658C:
	ldr r7, _082165FC @ =0x085AFEB2
	ldr r0, _08216600 @ =0x000012C4
	adds r5, r6, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sound_08240960
	cmp r0, #0
	beq _082165B6
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sound_08240740
_082165B6:
	ldr r0, _08216604 @ =0x000012BE
_082165B8:
	adds r4, r6, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl PlaySound_082406e0
	ldrh r0, [r4]
	strh r0, [r5]
_082165CE:
	ldr r0, _08216608 @ =0x00000424
	add r0, r8
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, #0xc0
	add r0, r8
	adds r1, r6, #0
	adds r1, #0x18
	movs r2, #0
	str r2, [sp]
	movs r2, #8
	movs r3, #1
	bl FUN_082370cc
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082165FC: .4byte 0x085AFEB2
_08216600: .4byte 0x000012C4
_08216604: .4byte 0x000012BE
_08216608: .4byte 0x00000424
