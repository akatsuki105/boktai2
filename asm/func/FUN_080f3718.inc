	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r7, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, _080F373C @ =0x00000474
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F3740
	movs r0, #1
	b _080F3742
	.align 2, 0
_080F373C: .4byte 0x00000474
_080F3740:
	movs r0, #0
_080F3742:
	cmp r0, #0
	bne _080F374A
	movs r0, #0
	b _080F3CC2
_080F374A:
	movs r3, #0x48
	adds r3, r3, r7
	mov sl, r3
	movs r4, #0
	str r4, [sp, #0x28]
	ldr r0, _080F379C @ =0x03002B4C
	ldr r0, [r0]
	adds r0, #0x24
	adds r1, r7, #0
	adds r1, #0x4e
	ldrb r0, [r0]
	adds r1, r1, r0
	mov r5, sl
	str r5, [sp, #0x2c]
	ldrb r1, [r1]
	cmp r4, r1
	blt _080F376E
	b _080F3CC0
_080F376E:
	ldr r0, _080F379C @ =0x03002B4C
	ldr r0, [r0]
	ldr r6, [sp, #0x28]
	lsls r1, r6, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sl
	adds r0, #8
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	ldrb r0, [r0, #6]
	cmp r0, #7
	bls _080F3790
	b _080F3C9A
_080F3790:
	lsls r0, r0, #2
	ldr r1, _080F37A0 @ =_080F37A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F379C: .4byte 0x03002B4C
_080F37A0: .4byte _080F37A4
_080F37A4: @ jump table
	.4byte _080F37C4 @ case 0
	.4byte _080F387C @ case 1
	.4byte _080F3976 @ case 2
	.4byte _080F3A98 @ case 3
	.4byte _080F39E8 @ case 4
	.4byte _080F3A50 @ case 5
	.4byte _080F3A64 @ case 6
	.4byte _080F3A80 @ case 7
_080F37C4:
	ldr r0, _080F3804 @ =0x000004A4
	adds r2, r7, r0
	ldr r1, [r2]
	mov r3, sb
	ldrh r0, [r3, #8]
	movs r3, #0
	strh r0, [r1, #0x1c]
	ldr r1, [r2]
	mov r4, sb
	ldrh r0, [r4, #0xa]
	strh r0, [r1, #0x1e]
	ldr r1, [r2]
	ldrh r0, [r4, #0xc]
	strh r0, [r1, #0x20]
	ldrh r1, [r4, #0xe]
	ldr r5, _080F3808 @ =0x00000482
	adds r0, r7, r5
	strh r1, [r0]
	movs r6, #0x10
	ldrsh r0, [r4, r6]
	cmp r0, #0
	beq _080F380C
	movs r0, #0x80
	lsls r0, r0, #2
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080F381A
	.align 2, 0
_080F3804: .4byte 0x000004A4
_080F3808: .4byte 0x00000482
_080F380C:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, _080F3860 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080F381A:
	ldr r3, _080F3864 @ =0x000004A4
	adds r0, r7, r3
	ldr r2, [r0]
	ldr r0, [r2, #0x1c]
	ldr r1, [r2, #0x20]
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
	movs r1, #2
	movs r3, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	movs r2, #0
	strb r1, [r0]
	ldr r5, _080F3868 @ =0x00000469
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _080F386C @ =0x0000046A
	adds r0, r7, r6
	strb r3, [r0]
	ldr r1, _080F3870 @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r3, _080F3874 @ =0x0000046C
	adds r0, r7, r3
	movs r1, #1
	strb r1, [r0]
	ldr r4, _080F3878 @ =FUN_080e48d0
	movs r3, #0x10
	adds r5, #4
	adds r0, r7, r5
	strb r1, [r0]
	adds r6, #1
	b _080F3A1C
	.align 2, 0
_080F3860: .4byte 0xFFFFFDFF
_080F3864: .4byte 0x000004A4
_080F3868: .4byte 0x00000469
_080F386C: .4byte 0x0000046A
_080F3870: .4byte 0x00000484
_080F3874: .4byte 0x0000046C
_080F3878: .4byte FUN_080e48d0
_080F387C:
	ldrb r0, [r7, #5]
	cmp r0, #0
	blt _080F3886
	asrs r0, r0, #5
	b _080F388C
_080F3886:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_080F388C:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	mov r5, sb
	movs r6, #8
	ldrsh r1, [r5, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080F38A0
	rsbs r1, r1, #0
_080F38A0:
	ldr r2, _080F38F8 @ =0x000001DF
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0x17
	bne _080F3910
	cmp r1, #0
	beq _080F396C
	mov r3, sb
	ldrb r0, [r3, #8]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r3, #0
	strb r0, [r1]
	movs r1, #2
	movs r2, #4
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _080F38FC @ =0x00000469
	adds r0, r7, r6
	strb r3, [r0]
	ldr r1, _080F3900 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _080F3904 @ =0x00000484
	adds r0, r7, r2
	str r3, [r0]
	ldr r4, _080F3908 @ =0x0000046C
	adds r0, r7, r4
	movs r1, #1
	strb r1, [r0]
	ldr r4, _080F390C @ =FUN_080e48d0
	movs r2, #0x10
	adds r5, #5
	adds r0, r7, r5
	strb r1, [r0]
	adds r6, #2
	b _080F39B6
	.align 2, 0
_080F38F8: .4byte 0x000001DF
_080F38FC: .4byte 0x00000469
_080F3900: .4byte 0x0000046A
_080F3904: .4byte 0x00000484
_080F3908: .4byte 0x0000046C
_080F390C: .4byte FUN_080e48d0
_080F3910:
	cmp r1, #1
	ble _080F396C
	mov r5, sb
	ldrh r1, [r5, #8]
	movs r6, #0xee
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r3, #0
	strb r1, [r0]
	movs r1, #2
	movs r2, #4
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _080F3958 @ =0x00000469
	adds r0, r7, r5
	strb r3, [r0]
	ldr r6, _080F395C @ =0x0000046A
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _080F3960 @ =0x00000484
	adds r0, r7, r1
	str r3, [r0]
	ldr r2, _080F3964 @ =0x0000046C
	adds r0, r7, r2
	movs r1, #1
	strb r1, [r0]
	ldr r4, _080F3968 @ =FUN_080e48d0
	movs r2, #0x10
	adds r5, #4
	adds r0, r7, r5
	strb r1, [r0]
	adds r6, #1
	b _080F39B6
	.align 2, 0
_080F3958: .4byte 0x00000469
_080F395C: .4byte 0x0000046A
_080F3960: .4byte 0x00000484
_080F3964: .4byte 0x0000046C
_080F3968: .4byte FUN_080e48d0
_080F396C:
	ldr r0, [sp, #0x2c]
	movs r1, #1
	bl FUN_08022488
	b _080F3C9A
_080F3976:
	mov r5, sb
	ldrb r0, [r5, #8]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	movs r3, #0
	strb r0, [r7, #5]
	movs r1, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r7, r6
	strb r1, [r0]
	ldr r2, _080F39D4 @ =0x00000469
	adds r0, r7, r2
	strb r3, [r0]
	ldr r4, _080F39D8 @ =0x0000046A
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _080F39DC @ =0x00000484
	adds r0, r7, r5
	str r3, [r0]
	adds r6, #4
	adds r0, r7, r6
	movs r1, #1
	strb r1, [r0]
	ldr r4, _080F39E0 @ =FUN_080e48d0
	movs r2, #0x10
	subs r5, #0x17
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #1
_080F39B6:
	adds r0, r7, r6
	strb r3, [r0]
	ldr r1, _080F39E4 @ =0x00000553
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r3, [r0]
	b _080F3C9A
	.align 2, 0
_080F39D4: .4byte 0x00000469
_080F39D8: .4byte 0x0000046A
_080F39DC: .4byte 0x00000484
_080F39E0: .4byte FUN_080e48d0
_080F39E4: .4byte 0x00000553
_080F39E8:
	movs r1, #2
	movs r3, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	movs r2, #0
	strb r1, [r0]
	ldr r6, _080F3A38 @ =0x00000469
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _080F3A3C @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _080F3A40 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	ldr r4, _080F3A44 @ =0x0000046C
	adds r0, r7, r4
	movs r1, #1
	strb r1, [r0]
	ldr r4, _080F3A48 @ =FUN_080e48d0
	movs r3, #0x10
	adds r5, #5
	adds r0, r7, r5
	strb r1, [r0]
	adds r6, #2
_080F3A1C:
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _080F3A4C @ =0x00000553
	adds r0, r7, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r7, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r2, [r0]
	b _080F3C9A
	.align 2, 0
_080F3A38: .4byte 0x00000469
_080F3A3C: .4byte 0x0000046A
_080F3A40: .4byte 0x00000484
_080F3A44: .4byte 0x0000046C
_080F3A48: .4byte FUN_080e48d0
_080F3A4C: .4byte 0x00000553
_080F3A50:
	add r1, sp, #0x1c
	movs r0, #6
	strh r0, [r1]
	ldr r5, _080F3A60 @ =0x000001DF
	adds r0, r7, r5
	ldrb r0, [r0]
	b _080F3A8C
	.align 2, 0
_080F3A60: .4byte 0x000001DF
_080F3A64:
	ldr r6, _080F3A7C @ =0x000001DF
	adds r2, r7, r6
	add r1, sp, #0x1c
	movs r0, #6
	strh r0, [r1]
	mov r3, sb
	ldrh r0, [r3, #8]
	strh r0, [r1, #2]
	ldrh r0, [r3, #0xa]
	strh r0, [r1, #4]
	b _080F3A8A
	.align 2, 0
_080F3A7C: .4byte 0x000001DF
_080F3A80:
	ldr r4, _080F3A94 @ =0x000001DF
	adds r2, r7, r4
	add r1, sp, #0x1c
	movs r0, #7
	strh r0, [r1]
_080F3A8A:
	ldrb r0, [r2]
_080F3A8C:
	ldrh r2, [r7]
	bl FUN_080ec848
	b _080F3C9A
	.align 2, 0
_080F3A94: .4byte 0x000001DF
_080F3A98:
	mov r5, sb
	movs r6, #8
	ldrsh r0, [r5, r6]
	cmp r0, #8
	bls _080F3AA4
	b _080F3C92
_080F3AA4:
	lsls r0, r0, #2
	ldr r1, _080F3AB0 @ =_080F3AB4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F3AB0: .4byte _080F3AB4
_080F3AB4: @ jump table
	.4byte _080F3AF0 @ case 0
	.4byte _080F3AD8 @ case 1
	.4byte _080F3AD8 @ case 2
	.4byte _080F3B08 @ case 3
	.4byte _080F3B20 @ case 4
	.4byte _080F3B80 @ case 5
	.4byte _080F3BE0 @ case 6
	.4byte _080F3C18 @ case 7
	.4byte _080F3C50 @ case 8
_080F3AD8:
	ldr r1, _080F3AEC @ =0x000001DF
	adds r0, r7, r1
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080e5718
	b _080F3C92
	.align 2, 0
_080F3AEC: .4byte 0x000001DF
_080F3AF0:
	ldr r2, _080F3B04 @ =0x000001DF
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080e5718
	b _080F3C92
	.align 2, 0
_080F3B04: .4byte 0x000001DF
_080F3B08:
	ldr r3, _080F3B1C @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	b _080F3C92
	.align 2, 0
_080F3B1C: .4byte 0x000001DF
_080F3B20:
	mov r4, sb
	ldrh r0, [r4, #0xa]
	movs r6, #0xc9
	lsls r6, r6, #1
	adds r5, r7, r6
	strh r0, [r5]
	ldrh r0, [r4, #0xc]
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r4, r7, r1
	strh r0, [r4]
	ldr r2, _080F3B78 @ =0x000001DF
	adds r2, r2, r7
	mov r8, r2
	ldrb r0, [r2]
	add r2, sp, #0x20
	add r3, sp, #0x24
	movs r1, #1
	bl FUN_080e5610
	adds r1, r7, #0
	adds r1, #8
	ldrh r2, [r7]
	ldr r3, [sp, #0x20]
	ldr r0, [sp, #0x24]
	str r0, [sp]
	mov r6, r8
	ldrb r0, [r6]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r5, #0
	ldrsh r0, [r4, r5]
	str r0, [sp, #0xc]
	movs r6, #0
	str r6, [sp, #0x10]
	str r7, [sp, #0x14]
	str r7, [sp, #0x18]
	movs r0, #0
	bl FUN_080d9cec
	ldr r2, _080F3B7C @ =0x00000454
	adds r1, r7, r2
	str r0, [r1]
	b _080F3C92
	.align 2, 0
_080F3B78: .4byte 0x000001DF
_080F3B7C: .4byte 0x00000454
_080F3B80:
	mov r3, sb
	ldrh r0, [r3, #0xa]
	movs r4, #0xc9
	lsls r4, r4, #1
	adds r5, r7, r4
	movs r6, #0
	mov r8, r6
	strh r0, [r5]
	ldrh r0, [r3, #0xc]
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r4, r7, r1
	strh r0, [r4]
	movs r2, #0xe
	ldrsh r6, [r3, r2]
	ldr r3, _080F3BD8 @ =0x000001DF
	adds r0, r7, r3
	ldrb r0, [r0]
	add r2, sp, #0x20
	add r3, sp, #0x24
	movs r1, #3
	bl FUN_080e5610
	adds r1, r7, #0
	adds r1, #8
	ldrh r2, [r7]
	ldr r3, [sp, #0x24]
	mov r0, r8
	str r0, [sp]
	str r5, [sp, #4]
	movs r5, #0
	ldrsh r0, [r4, r5]
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	str r7, [sp, #0x10]
	str r7, [sp, #0x14]
	movs r0, #7
	bl FUN_080da6c4
	ldr r6, _080F3BDC @ =0x00000454
	adds r1, r7, r6
	str r0, [r1]
	b _080F3C92
	.align 2, 0
_080F3BD8: .4byte 0x000001DF
_080F3BDC: .4byte 0x00000454
_080F3BE0:
	ldr r1, _080F3C10 @ =0x000001DF
	adds r0, r7, r1
	ldrb r0, [r0]
	add r2, sp, #0x20
	add r3, sp, #0x24
	movs r1, #1
	bl FUN_080e5610
	ldr r2, _080F3C14 @ =0x00000454
	adds r4, r7, r2
	ldr r0, [r4]
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	ldr r1, [sp, #0x24]
	str r1, [sp, #8]
	ldr r1, [sp, #0x20]
	str r1, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #5
	movs r3, #0
	bl FUN_080da9c4
	b _080F3C90
	.align 2, 0
_080F3C10: .4byte 0x000001DF
_080F3C14: .4byte 0x00000454
_080F3C18:
	ldr r3, _080F3C48 @ =0x000001DF
	adds r0, r7, r3
	ldrb r0, [r0]
	add r2, sp, #0x20
	add r3, sp, #0x24
	movs r1, #1
	bl FUN_080e5610
	ldr r5, _080F3C4C @ =0x00000454
	adds r4, r7, r5
	ldr r0, [r4]
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	ldr r1, [sp, #0x24]
	str r1, [sp, #8]
	ldr r1, [sp, #0x20]
	str r1, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #4
	movs r3, #0
	bl FUN_080da9c4
	b _080F3C90
	.align 2, 0
_080F3C48: .4byte 0x000001DF
_080F3C4C: .4byte 0x00000454
_080F3C50:
	ldr r6, _080F3CD4 @ =0x00000454
	adds r4, r7, r6
	ldr r0, [r4]
	ldrh r2, [r7]
	movs r1, #0
	bl FUN_080d99d4
	str r0, [r4]
	ldrh r2, [r7]
	movs r1, #1
	bl FUN_080d99d4
	str r0, [r4]
	ldrh r2, [r7]
	movs r1, #2
	bl FUN_080d99d4
	str r0, [r4]
	ldrh r2, [r7]
	movs r1, #4
	bl FUN_080d99d4
	str r0, [r4]
	ldrh r2, [r7]
	movs r1, #5
	bl FUN_080d99d4
	str r0, [r4]
	ldrh r2, [r7]
	movs r1, #3
	bl FUN_080d9a9c
_080F3C90:
	str r0, [r4]
_080F3C92:
	ldr r0, [sp, #0x2c]
	movs r1, #1
	bl FUN_08022488
_080F3C9A:
	mov r0, sl
	mov r1, sb
	bl FUN_08022474
	ldr r0, [sp, #0x28]
	adds r0, #1
	str r0, [sp, #0x28]
	ldr r0, _080F3CD8 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sl
	adds r0, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldr r1, [sp, #0x28]
	ldrb r0, [r0]
	cmp r1, r0
	bge _080F3CC0
	b _080F376E
_080F3CC0:
	movs r0, #1
_080F3CC2:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080F3CD4: .4byte 0x00000454
_080F3CD8: .4byte 0x03002B4C
