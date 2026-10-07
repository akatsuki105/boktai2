	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DE97A
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DE9CE
_081DE97A:
	ldr r3, [r4, #0x44]
	ldrh r2, [r3]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r2, r1
	movs r1, #0xe0
	lsls r1, r1, #5
	cmp r2, r1
	bne _081DE990
	movs r1, #1
	b _081DE992
_081DE990:
	movs r1, #0
_081DE992:
	cmp r1, #0
	beq _081DE9A8
	ldr r2, _081DE9A4 @ =FUN_081de9d8
	adds r0, r4, #0
	movs r1, #9
	bl Entity9A9F_SetState
	movs r0, #0
	b _081DE9CE
	.align 2, 0
_081DE9A4: .4byte FUN_081de9d8
_081DE9A8:
	ldrh r1, [r3]
	movs r2, #0xf0
	lsls r2, r2, #6
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #3
	cmp r1, r2
	bne _081DE9BC
	movs r1, #1
	b _081DE9BE
_081DE9BC:
	movs r1, #0
_081DE9BE:
	cmp r1, #0
	beq _081DE9CE
	ldr r2, _081DE9D4 @ =FUN_081de360
	adds r0, r4, #0
	movs r1, #4
	bl Entity9A9F_SetState
	movs r0, #0
_081DE9CE:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DE9D4: .4byte FUN_081de360
