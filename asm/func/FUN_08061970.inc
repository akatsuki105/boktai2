	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	mov ip, r1
	ldr r0, _08061988 @ =0x000006AC
	adds r4, r5, r0
	cmp r3, #0
	bne _0806198C
	movs r3, #0xa0
	movs r7, #0xe1
	lsls r7, r7, #1
	b _0806199C
	.align 2, 0
_08061988: .4byte 0x000006AC
_0806198C:
	cmp r3, #1
	bne _08061998
	movs r3, #0x8c
	movs r7, #0xa9
	lsls r7, r7, #1
	b _0806199C
_08061998:
	movs r3, #0x78
	movs r7, #0xe0
_0806199C:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r6, r0, #5
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldrh r0, [r4, #0x1e]
	adds r0, r0, r3
	strh r0, [r4, #0x1e]
	ldr r2, _080619D8 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	blt _080619DC
	asrs r1, r0, #0xc
	b _080619E2
	.align 2, 0
_080619D8: .4byte 0x085B0A08
_080619DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080619E2:
	ldrh r0, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080619FA
	asrs r1, r0, #0xc
	b _08061A00
_080619FA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08061A00:
	ldrh r0, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08061A24
	asrs r1, r0, #0xc
	b _08061A2A
_08061A24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08061A2A:
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r0, r5, r3
	strh r1, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08061A48
	asrs r2, r0, #0xc
	b _08061A4E
_08061A48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08061A4E:
	ldr r3, _08061A8C @ =0x0000070C
	adds r0, r5, r3
	strh r2, [r0]
	add r2, sp, #8
	mov r0, ip
	add r1, sp, #4
	bl FUN_080617dc
	ldr r1, _08061A90 @ =0x000006F4
	adds r0, r5, r1
	ldr r2, _08061A94 @ =0x00000704
	adds r1, r5, r2
	ldr r1, [r1]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r2, [sp, #8]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #1
	bl FUN_08236fac
	adds r0, r5, #0
	bl FUN_0806181c
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061A8C: .4byte 0x0000070C
_08061A90: .4byte 0x000006F4
_08061A94: .4byte 0x00000704
