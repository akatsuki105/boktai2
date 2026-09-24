	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _0809D918 @ =0x0000C091
	ldr r1, _0809D91C @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r6, #0x1c]
	movs r0, #6
	str r0, [sp, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r2, #0
	movs r5, #1
_0809D8B6:
	ldr r1, _0809D920 @ =0x00000F71
	adds r0, r6, r1
	ldrb r0, [r0]
	asrs r0, r2
	ands r0, r5
	adds r4, r2, #1
	cmp r0, #0
	bne _0809D8EA
	adds r0, r2, #0
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, #2
	asrs r2, r2, #1
	adds r2, #4
	movs r0, #3
	bl FUN_0809d858
	movs r2, #1
	movs r1, #1
_0809D8E0:
	strh r2, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0809D8E0
_0809D8EA:
	adds r2, r4, #0
	cmp r2, #3
	ble _0809D8B6
	ldr r4, _0809D924 @ =0x000092B3
	ldr r0, _0809D928 @ =0x08251D6C
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x20]
	ldr r1, _0809D92C @ =0x03004250
	ldr r2, _0809D930 @ =0x04000018
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D918: .4byte 0x0000C091
_0809D91C: .4byte 0x0000CD91
_0809D920: .4byte 0x00000F71
_0809D924: .4byte 0x000092B3
_0809D928: .4byte 0x08251D6C
_0809D92C: .4byte 0x03004250
_0809D930: .4byte 0x04000018
