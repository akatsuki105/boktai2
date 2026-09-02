	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08061C00 @ =0x000006AC
	adds r4, r6, r0
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r5, r6, r1
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _08061C10
	ldr r1, _08061C04 @ =0x00002110
	adds r0, r5, #0
	bl Video_GetActorSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x43
	bl FUN_0822a470
	movs r0, #4
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	movs r1, #0x32
	bl FUN_0822b20c
	movs r0, #1
	strb r0, [r4, #7]
	movs r0, #0x7f
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldr r0, _08061C08 @ =0x00000714
	adds r1, r6, r0
	ldr r0, _08061C0C @ =FUN_080617bc
	b _08061C3E
	.align 2, 0
_08061C00: .4byte 0x000006AC
_08061C04: .4byte 0x00002110
_08061C08: .4byte 0x00000714
_08061C0C: .4byte FUN_080617bc
_08061C10:
	ldr r1, _08061C50 @ =0x00008F5D
	adds r0, r5, #0
	bl Video_GetActorSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0822a470
	adds r0, r5, #0
	movs r1, #0x1d
	bl FUN_0822b20c
	ldr r0, _08061C54 @ =0x0000922E
	ldr r1, _08061C58 @ =0x00000837
	bl GetFile
	ldr r2, _08061C5C @ =0x00000704
	adds r1, r6, r2
	str r0, [r1]
	ldr r0, _08061C60 @ =0x00000714
	adds r1, r6, r0
	ldr r0, _08061C64 @ =FUN_08061680
_08061C3E:
	str r0, [r1]
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08061C50: .4byte 0x00008F5D
_08061C54: .4byte 0x0000922E
_08061C58: .4byte 0x00000837
_08061C5C: .4byte 0x00000704
_08061C60: .4byte 0x00000714
_08061C64: .4byte FUN_08061680
