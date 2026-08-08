	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0807E87A
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0807E8A8 @ =0x00000381
	adds r0, r5, r3
	strb r1, [r0]
_0807E87A:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807E8B4
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807E8AC @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r3, _0807E8B0 @ =0x000002E7
	adds r1, r5, r3
	movs r0, #1
	b _0807E8C2
	.align 2, 0
_0807E8A8: .4byte 0x00000381
_0807E8AC: .4byte 0x000002E6
_0807E8B0: .4byte 0x000002E7
_0807E8B4:
	lsrs r1, r1, #0x19
	ldr r2, _0807E93C @ =0x000002E6
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0807E940 @ =0x000002E7
	adds r1, r5, r3
	movs r0, #0
_0807E8C2:
	strb r0, [r1]
	movs r0, #4
	str r0, [r5, #0x1c]
	ldr r1, _0807E944 @ =0x0000037D
	adds r0, r5, r1
	movs r4, #0
	strb r4, [r0]
	ldr r2, _0807E948 @ =0x0000037E
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	subs r2, #0xfb
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0807E94C @ =0x03002BD0
	strh r4, [r0]
	ldr r0, _0807E950 @ =0x03002B80
	strh r4, [r0]
	ldr r0, _0807E954 @ =0x03002B78
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_08063220
	ldr r3, _0807E958 @ =0x00000442
	adds r0, r5, r3
	strh r4, [r0]
	ldr r1, _0807E95C @ =0x00000444
	adds r0, r5, r1
	strh r4, [r0]
	ldr r2, _0807E960 @ =0x00000446
	adds r0, r5, r2
	strh r4, [r0]
	movs r2, #0
	movs r1, #2
	subs r3, #2
	adds r0, r5, r3
_0807E912:
	strh r2, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0807E912
	adds r0, r5, #0
	bl FUN_08060c60
	ldr r1, _0807E964 @ =0x000003CE
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0807E934
	adds r0, r5, #0
	bl FUN_08066d10
_0807E934:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807E93C: .4byte 0x000002E6
_0807E940: .4byte 0x000002E7
_0807E944: .4byte 0x0000037D
_0807E948: .4byte 0x0000037E
_0807E94C: .4byte 0x03002BD0
_0807E950: .4byte 0x03002B80
_0807E954: .4byte 0x03002B78
_0807E958: .4byte 0x00000442
_0807E95C: .4byte 0x00000444
_0807E960: .4byte 0x00000446
_0807E964: .4byte 0x000003CE
