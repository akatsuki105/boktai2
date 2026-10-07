	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE878
	bl FUN_081dc694
	ldr r1, _081DE890 @ =0x000002EA
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	bl VM_ExecByID
	ldr r0, _081DE894 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE878
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DE878
	movs r0, #0xa8
	bl sound_08240264
_081DE878:
	adds r0, r4, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DE898
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DE95A
	.align 2, 0
_081DE890: .4byte 0x000002EA
_081DE894: .4byte 0x03002C68
_081DE898:
	ldr r2, [r4, #0x44]
	ldrh r1, [r2]
	movs r0, #0xf0
	lsls r0, r0, #6
	ands r1, r0
	movs r0, #0xe0
	lsls r0, r0, #5
	cmp r1, r0
	bne _081DE8AE
	movs r0, #1
	b _081DE8B0
_081DE8AE:
	movs r0, #0
_081DE8B0:
	cmp r0, #0
	beq _081DE8C4
	ldr r2, _081DE8C0 @ =FUN_081de9d8
	adds r0, r4, #0
	movs r1, #9
	bl Entity9A9F_SetState
	b _081DE958
	.align 2, 0
_081DE8C0: .4byte FUN_081de9d8
_081DE8C4:
	ldrh r0, [r2]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	bne _081DE8D8
	movs r0, #1
	b _081DE8DA
_081DE8D8:
	movs r0, #0
_081DE8DA:
	cmp r0, #0
	beq _081DE908
	ldr r2, _081DE900 @ =FUN_081de360
	adds r0, r4, #0
	movs r1, #4
	bl Entity9A9F_SetState
	ldr r0, _081DE904 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE958
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DE958
	movs r0, #1
	bl Sound_FadeOutBGM
	b _081DE958
	.align 2, 0
_081DE900: .4byte FUN_081de360
_081DE904: .4byte 0x03002C68
_081DE908:
	ldr r0, _081DE934 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE958
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DE958
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq _081DE958
	cmp r1, #1
	bne _081DE938
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, #0x1f
	strh r1, [r0]
	b _081DE954
	.align 2, 0
_081DE934: .4byte 0x03002C68
_081DE938:
	cmp r1, #2
	bne _081DE954
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	bl VM_ExecByID
_081DE954:
	movs r0, #0
	strb r0, [r5]
_081DE958:
	movs r0, #0
_081DE95A:
	pop {r4, r5}
	pop {r1}
	bx r1
