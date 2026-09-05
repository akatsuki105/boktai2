	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0803c1c0
FUN_0803c1c0: @ 0x0803C1C0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r7, r5, #0
	bl FUN_08236524
	ldrh r0, [r6, #0x3e]
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r4, #6]
	ands r0, r1
	cmp r0, #0
	beq _0803C1F4
	adds r0, r4, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r3, _0803C1F0 @ =0x0000016B
	adds r1, r5, r3
	b _0803C210
	.align 2, 0
_0803C1F0: .4byte 0x0000016B
_0803C1F4:
	movs r1, #0x24
	ldrsh r0, [r6, r1]
	movs r2, #0x24
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r6, r3]
	movs r3, #0x28
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r2, _0803C25C @ =0x0000016B
	adds r1, r5, r2
_0803C210:
	strb r0, [r1]
	ldr r3, [r4, #0x34]
	adds r0, r7, #0
	adds r0, #0xb4
	str r3, [r0]
	ldr r4, [r4, #0x38]
	adds r0, #4
	str r4, [r0]
	movs r0, #0xa9
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0803C246
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
_0803C246:
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	str r4, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C25C: .4byte 0x0000016B
_0803C260:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_0803c264
FUN_0803c264: @ 0x0803C264
	push {lr}
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r0, r1
	bl FUN_08236424
	pop {r0}
	bx r0

	thumb_func_start FUN_0803c274
FUN_0803c274: @ 0x0803C274
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	adds r2, #0x48
	mov ip, r2
	ldrb r1, [r2, #5]
	subs r1, #0x20
	movs r2, #0x40
	rsbs r2, r2, #0
	ands r1, r2
	adds r5, r1, #0
	adds r5, #0x40
	movs r6, #0xa4
	ldr r3, _0803C2AC @ =0x085B0A08
	adds r1, r5, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r6, r1
	cmp r1, #0
	blt _0803C2B0
	asrs r2, r1, #0xc
	b _0803C2B6
	.align 2, 0
_0803C2AC: .4byte 0x085B0A08
_0803C2B0:
	rsbs r1, r1, #0
	asrs r1, r1, #0xc
	rsbs r2, r1, #0
_0803C2B6:
	movs r1, #0
	strh r2, [r4]
	strh r1, [r4, #2]
	movs r1, #0xff
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	muls r1, r6, r1
	cmp r1, #0
	blt _0803C2D2
	asrs r1, r1, #0xc
	b _0803C2D8
_0803C2D2:
	rsbs r1, r1, #0
	asrs r1, r1, #0xc
	rsbs r1, r1, #0
_0803C2D8:
	strh r1, [r4, #4]
	cmp r5, #0
	bne _0803C2E4
	subs r1, #0x20
	strh r1, [r4, #4]
	b _0803C302
_0803C2E4:
	cmp r5, #0x40
	bne _0803C2EE
	ldrh r1, [r4]
	subs r1, #0x20
	b _0803C300
_0803C2EE:
	cmp r5, #0x80
	bne _0803C2F8
	adds r1, #0x20
	strh r1, [r4, #4]
	b _0803C302
_0803C2F8:
	cmp r5, #0xc0
	bne _0803C302
	ldrh r1, [r4]
	adds r1, #0x20
_0803C300:
	strh r1, [r4]
_0803C302:
	mov r2, ip
	adds r2, #8
	mov r3, ip
	ldrh r1, [r3, #8]
	ldrh r3, [r4]
	adds r1, r1, r3
	strh r1, [r4]
	ldrh r1, [r2, #2]
	ldrh r3, [r4, #2]
	adds r1, r1, r3
	strh r1, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	strh r1, [r4, #4]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0803c328
FUN_0803c328: @ 0x0803C328
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x48
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x15
	movs r0, #0x82
	lsls r0, r0, #4
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, r2
	ble _0803C358
	subs r0, #1
	b _0803C35E
_0803C358:
	cmp r0, r2
	bge _0803C360
	adds r0, #1
_0803C35E:
	strh r0, [r1]
_0803C360:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #0x80
	subs r3, r0, r1
	ldr r2, _0803C37C @ =0x00000822
	adds r0, r4, r2
	ldrh r0, [r0]
	muls r0, r3, r0
	cmp r0, #0
	blt _0803C380
	asrs r0, r0, #7
	b _0803C386
	.align 2, 0
_0803C37C: .4byte 0x00000822
_0803C380:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_0803C386:
	adds r3, r0, #0
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r2, #8
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	muls r0, r3, r0
	cmp r0, #0
	blt _0803C39C
	asrs r1, r0, #8
	b _0803C3A2
_0803C39C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0803C3A2:
	ldrh r0, [r5]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0803C3D8 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldrh r1, [r5, #2]
	adds r1, #0x78
	lsls r1, r1, #0x10
	ldr r0, _0803C3DC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r1, #4
	ldrsh r0, [r5, r1]
	movs r2, #0xc
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	muls r0, r3, r0
	cmp r0, #0
	blt _0803C3E0
	asrs r1, r0, #8
	b _0803C3E6
	.align 2, 0
_0803C3D8: .4byte 0xFFFF0000
_0803C3DC: .4byte 0x0000FFFF
_0803C3E0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0803C3E6:
	ldrh r0, [r5, #4]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _0803C408 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	bl FUN_0823b8ac
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803C408: .4byte 0xFFFF0000

	thumb_func_start FUN_0803c40c
FUN_0803c40c: @ 0x0803C40C
	push {r4, r5, r6, lr}
	adds r5, r2, #0
	adds r6, r3, #0
	movs r2, #0
	ldrsh r3, [r1, r2]
	movs r4, #0
	ldrsh r2, [r0, r4]
	subs r3, r3, r2
	movs r2, #4
	ldrsh r1, [r1, r2]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r2, r1, r0
	adds r1, r3, #0
	muls r1, r3, r1
	adds r0, r2, #0
	muls r0, r2, r0
	adds r4, r1, r0
	cmp r4, #0
	bne _0803C43A
	strb r4, [r5]
	strh r4, [r6]
	b _0803C44C
_0803C43A:
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0823785c
	strb r0, [r5]
	adds r0, r4, #0
	bl Sqrt
	strh r0, [r6]
_0803C44C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803c454
FUN_0803c454: @ 0x0803C454
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	mov r3, sp
	ldr r2, _0803C484 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0803C488
	asrs r1, r0, #0xc
	b _0803C48E
	.align 2, 0
_0803C484: .4byte 0x085B0A08
_0803C488:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803C48E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0803C4A6
	asrs r0, r0, #0xc
	b _0803C4AC
_0803C4A6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803C4AC:
	strh r0, [r3, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r5]
	mov r1, sp
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r4, [r4, #4]
	adds r0, r0, r4
	strh r0, [r5, #4]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803c4d4
FUN_0803c4d4: @ 0x0803C4D4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r2, #0
	movs r0, #0xa5
	lsls r0, r0, #2
	adds r2, r6, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r6, r1
	mov r4, sp
	adds r4, #2
	adds r1, r2, #0
	mov r2, sp
	adds r3, r4, #0
	bl FUN_0803c40c
	movs r3, #0x9d
	lsls r3, r3, #2
	adds r2, r6, r3
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #8
	str r0, [r2]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r4]
	lsls r0, r0, #8
	str r0, [r1]
	adds r3, #0x14
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0803C54C @ =0x0000028A
	adds r0, r6, r1
	strh r5, [r0]
	subs r3, #0x18
	adds r0, r6, r3
	ldr r1, [r2]
	ldr r0, [r0]
	subs r2, r1, r0
	adds r1, r2, #0
	cmp r2, #0
	bge _0803C538
	rsbs r1, r2, #0
_0803C538:
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r1, r0
	ble _0803C564
	cmp r2, #0
	bge _0803C550
	movs r0, #0x80
	lsls r0, r0, #9
	adds r2, r2, r0
	b _0803C554
	.align 2, 0
_0803C54C: .4byte 0x0000028A
_0803C550:
	ldr r1, _0803C58C @ =0xFFFF0000
	adds r2, r2, r1
_0803C554:
	movs r3, #0x9d
	lsls r3, r3, #2
	adds r1, r6, r3
	subs r3, #4
	adds r0, r6, r3
	ldr r0, [r0]
	adds r0, r0, r2
	str r0, [r1]
_0803C564:
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r3, #0xa1
	lsls r3, r3, #2
	adds r1, r6, r3
	adds r2, #0xc
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803C58C: .4byte 0xFFFF0000

	thumb_func_start FUN_0803c590
FUN_0803c590: @ 0x0803C590
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x50
	mov r4, sp
	adds r4, #2
	mov r2, sp
	adds r3, r4, #0
	bl FUN_0803c40c
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r1, r5, r0
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #8
	str r0, [r1]
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r4]
	lsls r0, r0, #8
	str r0, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803c5d0
FUN_0803c5d0: @ 0x0803C5D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r4, r7, r0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldr r1, _0803C65C @ =0x0000028A
	adds r1, r1, r7
	mov r8, r1
	ldrh r1, [r1]
	ldrh r3, [r4]
	subs r5, r1, r3
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	muls r0, r5, r0
	movs r6, #0x9d
	lsls r6, r6, #2
	adds r2, r7, r6
	ldr r2, [r2]
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r3, r7, r1
	str r0, [r3]
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	muls r0, r5, r0
	adds r6, #0xc
	adds r1, r7, r6
	ldrh r2, [r4]
	ldr r1, [r1]
	muls r1, r2, r1
	adds r0, r0, r1
	mov r2, r8
	ldrh r1, [r2]
	str r3, [sp]
	bl Div
	subs r6, #4
	adds r1, r7, r6
	str r0, [r1]
	ldr r3, [sp]
	ldr r0, [r3]
	cmp r0, #0
	bge _0803C64A
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	str r0, [r3]
_0803C64A:
	ldrh r0, [r3]
	str r0, [r3]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C65C: .4byte 0x0000028A

	thumb_func_start FUN_0803c660
FUN_0803c660: @ 0x0803C660
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0x50
	movs r0, #0xa3
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r0, #0
	blt _0803C67E
	asrs r0, r0, #8
	b _0803C684
_0803C67E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0803C684:
	lsls r2, r0, #0x18
	lsrs r2, r2, #0x18
	movs r5, #0x9f
	lsls r5, r5, #2
	adds r0, r3, r5
	ldr r3, [r0]
	lsls r3, r3, #8
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	bl FUN_0803c454
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803c6a0
FUN_0803c6a0: @ 0x0803C6A0
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	adds r3, r0, #0
	cmp r3, #0
	beq _0803C6E6
	movs r5, #0
	ldrsh r1, [r3, r5]
	movs r6, #0
	ldrsh r0, [r4, r6]
	movs r5, #0
	cmp r1, r0
	blt _0803C6DE
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bgt _0803C6DE
	movs r0, #4
	ldrsh r3, [r3, r0]
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r3, r0
	blt _0803C6DE
	movs r6, #4
	ldrsh r0, [r2, r6]
	cmp r3, r0
	bgt _0803C6DE
	movs r5, #1
_0803C6DE:
	cmp r5, #0
	beq _0803C6E6
	movs r0, #0
	b _0803C6EA
_0803C6E6:
	movs r0, #1
	rsbs r0, r0, #0
_0803C6EA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0803c6f0
FUN_0803c6f0: @ 0x0803C6F0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	mov r8, r1
	movs r0, #7
	mov sb, r0
	ldr r1, _0803C75C @ =0x00000834
	adds r4, r5, r1
	movs r7, #0
	movs r6, #2
_0803C70A:
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r2, r8
	str r2, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0xcb
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	ldr r3, _0803C760 @ =0x00000201
	bl FUN_0822f3fc
	movs r0, #0x86
	lsls r0, r0, #7
	strh r0, [r4, #0x3a]
	ldr r0, _0803C764 @ =0x03003584
	mov r1, sb
	lsls r2, r1, #5
	ldr r1, [r0]
	adds r1, r1, r2
	ldr r2, _0803C768 @ =0x0000087C
	adds r0, r5, r2
	adds r0, r0, r7
	str r1, [r0]
	adds r4, #0x60
	adds r7, #0x60
	subs r6, #1
	cmp r6, #0
	bge _0803C70A
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C75C: .4byte 0x00000834
_0803C760: .4byte 0x00000201
_0803C764: .4byte 0x03003584
_0803C768: .4byte 0x0000087C

	thumb_func_start FUN_0803c76c
FUN_0803c76c: @ 0x0803C76C
	push {r4, r5, lr}
	ldr r1, _0803C788 @ =0x00000834
	adds r4, r0, r1
	movs r5, #2
_0803C774:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0803C774
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803C788: .4byte 0x00000834

	thumb_func_start FUN_0803c78c
FUN_0803c78c: @ 0x0803C78C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r7, r1, #0
	mov r8, r2
	ldr r0, _0803C7EC @ =0x00000826
	adds r5, r4, r0
	ldrh r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _0803C7F0 @ =0x0000083C
	adds r6, r4, r1
	adds r0, r6, r0
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldrh r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r2, _0803C7F4 @ =0x00000834
	adds r0, r0, r2
	adds r0, r4, r0
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #9
	bl FUN_0822f588
	ldrh r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803C7F8
	ldrh r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r6, r0
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	b _0803C808
	.align 2, 0
_0803C7EC: .4byte 0x00000826
_0803C7F0: .4byte 0x0000083C
_0803C7F4: .4byte 0x00000834
_0803C7F8:
	ldrh r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r6, r0
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
_0803C808:
	orrs r1, r2
	str r1, [r0]
	ldr r5, _0803C854 @ =0x00000826
	adds r3, r4, r5
	ldrh r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r4, r0
	ldr r1, _0803C858 @ =0x00000854
	adds r0, r0, r1
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0]
	str r2, [r0, #4]
	ldrh r1, [r3]
	lsls r1, r1, #1
	adds r5, #8
	adds r0, r4, r5
	adds r0, r0, r1
	mov r1, r8
	strh r1, [r0]
	ldrh r0, [r3]
	lsls r0, r0, #1
	ldr r2, _0803C85C @ =0x00000828
	adds r1, r4, r2
	adds r1, r1, r0
	movs r0, #0xc
	strh r0, [r1]
	cmp r7, #0
	beq _0803C860
	cmp r7, #1
	bne _0803C860
	movs r1, #0xb
	b _0803C868
	.align 2, 0
_0803C854: .4byte 0x00000826
_0803C858: .4byte 0x00000854
_0803C85C: .4byte 0x00000828
_0803C860:
	adds r0, r4, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
_0803C868:
	ldr r0, _0803C8A8 @ =0x03003584
	lsls r1, r1, #5
	ldr r2, [r0]
	adds r2, r2, r1
	ldr r5, _0803C8AC @ =0x00000826
	adds r3, r4, r5
	ldrh r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r5, #0x56
	adds r0, r4, r5
	adds r0, r0, r1
	str r2, [r0]
	ldrh r0, [r3]
	adds r0, #1
	movs r1, #0
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _0803C896
	strh r1, [r3]
_0803C896:
	ldr r2, _0803C8B0 @ =0x00000824
	adds r0, r4, r2
	strh r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C8A8: .4byte 0x03003584
_0803C8AC: .4byte 0x00000826
_0803C8B0: .4byte 0x00000824

	thumb_func_start FUN_0803c8b4
FUN_0803c8b4: @ 0x0803C8B4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0803C8F4 @ =0x0000083C
	adds r3, r4, r0
	subs r0, #0x14
	adds r2, r4, r0
	movs r5, #1
	movs r1, #2
_0803C8C4:
	ldrh r0, [r2]
	cmp r0, #0
	beq _0803C8DA
	subs r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0803C8DA
	ldr r0, [r3]
	orrs r0, r5
	str r0, [r3]
_0803C8DA:
	adds r3, #0x60
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bge _0803C8C4
	ldr r0, _0803C8F8 @ =0x00000824
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803C8F4: .4byte 0x0000083C
_0803C8F8: .4byte 0x00000824

	thumb_func_start FUN_0803c8fc
FUN_0803c8fc: @ 0x0803C8FC
	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r0, r3, r2
	ldr r2, [r0]
	cmp r1, r2
	bhs _0803C92C
	movs r4, #0xc8
	lsls r4, r4, #2
	adds r0, r3, r4
	movs r4, #1
	ldr r3, [r0]
_0803C918:
	adds r0, r4, #0
	lsls r0, r1
	ands r0, r3
	cmp r0, #0
	bne _0803C926
	adds r0, r1, #0
	b _0803C930
_0803C926:
	adds r1, #1
	cmp r1, r2
	blo _0803C918
_0803C92C:
	movs r0, #1
	rsbs r0, r0, #0
_0803C930:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0803c938
FUN_0803c938: @ 0x0803C938
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r4, r1, #0
	mov r8, r2
	bl FUN_0803c8fc
	adds r6, r0, #0
	movs r0, #0xc5
	lsls r0, r0, #2
	adds r7, r5, r0
	ldr r0, [r7]
	cmp r0, #0
	beq _0803C9A8
	cmp r6, #0
	blt _0803C9A8
	lsls r1, r6, #1
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	str r0, [sp]
	movs r1, #0
	ldrsh r0, [r4, r1]
	str r0, [sp, #4]
	movs r2, #2
	ldrsh r0, [r4, r2]
	str r0, [sp, #8]
	movs r1, #4
	ldrsh r0, [r4, r1]
	str r0, [sp, #0xc]
	mov r2, r8
	str r2, [sp, #0x10]
	ldr r1, _0803C9B4 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	movs r1, #5
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	mov r0, sp
	str r0, [r1, #4]
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r3, r5, r2
	movs r2, #1
	lsls r2, r6
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r7]
	bl Script_ExecById
_0803C9A8:
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C9B4: .4byte 0xFFFF0000

	thumb_func_start FUN_0803c9b8
FUN_0803c9b8: @ 0x0803C9B8
	push {r4, r5, r6, r7, lr}
	movs r0, #7
	bl FUN_08022a2c
	adds r5, r0, #0
	cmp r5, #0
	beq _0803CA0E
	adds r0, #0x97
	ldrb r0, [r0]
	cmp r0, #7
	bne _0803CA0E
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r3, #0
	movs r0, #0xc7
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r3, r0
	bhs _0803CA0E
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r4, r5, r0
	adds r6, r1, #0
	adds r0, #4
	adds r2, r5, r0
	movs r5, #1
_0803C9F4:
	ldrh r0, [r2]
	cmp r0, r7
	bne _0803CA04
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	bics r0, r1
	str r0, [r4]
_0803CA04:
	adds r2, #2
	adds r3, #1
	ldr r0, [r6]
	cmp r3, r0
	blo _0803C9F4
_0803CA0E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803ca14
FUN_0803ca14: @ 0x0803CA14
	push {lr}
	movs r0, #7
	bl FUN_08022a2c
	adds r1, r0, #0
	cmp r1, #0
	beq _0803CA3C
	adds r0, #0x97
	ldrb r0, [r0]
	cmp r0, #7
	bne _0803CA3C
	movs r2, #0xc6
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _0803CA3C
	movs r1, #0
	bl Script_ExecById
_0803CA3C:
	pop {r0}
	bx r0

	thumb_func_start FUN_0803ca40
FUN_0803ca40: @ 0x0803CA40
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x18
	mov sl, r0
	ldr r3, _0803CB10 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0xa4
	orrs r0, r2
	ldr r1, _0803CB14 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x14]
	ldr r6, _0803CB18 @ =0x0203B400
	ldr r0, _0803CB1C @ =0x030046B8
	mov sb, r0
	ldr r0, [r0]
	adds r0, #1
	ldr r5, _0803CB20 @ =0x000003FF
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrb r3, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	movs r2, #3
	mov r8, r2
	ands r1, r2
	adds r1, #2
	adds r0, #1
	ands r0, r5
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	adds r0, #0x14
	str r1, [sp]
	str r0, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	movs r1, #3
	add r2, sp, #0x10
	bl FUN_080ddcc8
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrb r3, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	mov r2, r8
	ands r1, r2
	adds r1, #2
	adds r0, #1
	ands r0, r5
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	adds r0, #0x14
	str r1, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	movs r1, #3
	add r2, sp, #0x10
	bl FUN_080ddcc8
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803CB10: .4byte 0xFFFF0000
_0803CB14: .4byte 0x0000FFFF
_0803CB18: .4byte 0x0203B400
_0803CB1C: .4byte 0x030046B8
_0803CB20: .4byte 0x000003FF

	thumb_func_start FUN_0803cb24
FUN_0803cb24: @ 0x0803CB24
	push {lr}
	movs r0, #7
	bl FUN_08022a2c
	adds r2, r0, #0
	cmp r2, #0
	beq _0803CB42
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r0, r2, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0803CB48 @ =0x000002C1
	adds r0, r2, r3
	strb r1, [r0]
_0803CB42:
	pop {r0}
	bx r0
	.align 2, 0
_0803CB48: .4byte 0x000002C1

	thumb_func_start FUN_0803cb4c
FUN_0803cb4c: @ 0x0803CB4C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #7
	bl FUN_08022a2c
	cmp r0, #0
	beq _0803CB60
	ldr r1, _0803CB68 @ =0x000002C1
	adds r0, r0, r1
	strb r4, [r0]
_0803CB60:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CB68: .4byte 0x000002C1

	thumb_func_start FUN_0803cb6c
FUN_0803cb6c: @ 0x0803CB6C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r0, #7
	bl FUN_08022a2c
	adds r5, r0, #0
	cmp r5, #0
	beq _0803CBAA
	cmp r6, #0
	ble _0803CB9C
	adds r4, r6, #0
_0803CB84:
	mov r0, sp
	movs r1, #8
	bl FUN_08235090
	adds r0, r5, #0
	mov r1, sp
	adds r2, r6, #0
	bl FUN_0803c938
	subs r4, #1
	cmp r4, #0
	bne _0803CB84
_0803CB9C:
	movs r0, #0xa3
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #1
	movs r1, #0
	bl FUN_08050e2c
_0803CBAA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803cbb4
FUN_0803cbb4: @ 0x0803CBB4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #7
	bl FUN_08022a2c
	adds r7, r0, #0
	cmp r7, #0
	beq _0803CC4A
	cmp r6, #1
	beq _0803CBCC
	cmp r6, #4
	bne _0803CBE6
_0803CBCC:
	movs r0, #0x82
	lsls r0, r0, #1
	adds r5, r7, r0
	ldr r4, [r5]
	adds r0, r6, #0
	movs r1, #3
	bl Div
	adds r2, r0, #0
	adds r2, #1
	adds r0, r4, #0
	movs r1, #1
	b _0803CC06
_0803CBE6:
	cmp r6, #2
	beq _0803CBEE
	cmp r6, #5
	bne _0803CC0E
_0803CBEE:
	movs r1, #0x82
	lsls r1, r1, #1
	adds r5, r7, r1
	ldr r4, [r5]
	adds r0, r6, #0
	movs r1, #3
	bl Div
	adds r2, r0, #0
	adds r2, #1
	adds r0, r4, #0
	movs r1, #3
_0803CC06:
	bl FUN_0807ae6c
	adds r4, r5, #0
	b _0803CC3E
_0803CC0E:
	movs r3, #0x82
	lsls r3, r3, #1
	adds r4, r7, r3
	ldr r5, [r4]
	adds r0, r6, #0
	movs r1, #3
	bl Div
	movs r1, #0xc4
	lsls r1, r1, #2
	adds r2, r7, r1
	ldr r3, _0803CC50 @ =0x00000311
	adds r1, r7, r3
	ldrb r1, [r1]
	muls r0, r1, r0
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r2, r0, #4
	subs r2, r2, r0
	lsls r2, r2, #2
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08063574
_0803CC3E:
	ldr r2, [r4]
	adds r2, #0x2c
	movs r0, #2
	movs r1, #0
	bl FUN_08050e2c
_0803CC4A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CC50: .4byte 0x00000311

	thumb_func_start FUN_0803cc54
FUN_0803cc54: @ 0x0803CC54
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #7
	bl FUN_08022a2c
	cmp r0, #0
	beq _0803CC6A
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r0, r0, r1
	strb r4, [r0]
_0803CC6A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803cc70
FUN_0803cc70: @ 0x0803CC70
	push {r4, lr}
	movs r0, #7
	bl FUN_08022a2c
	adds r4, r0, #0
	cmp r4, #0
	beq _0803CC96
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, _0803CC9C @ =0x00000802
	movs r1, #0
	movs r3, #1
	bl FUN_08236514
	ldr r0, _0803CCA0 @ =0x000002B6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0803CC96:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CC9C: .4byte 0x00000802
_0803CCA0: .4byte 0x000002B6

	thumb_func_start FUN_0803cca4
FUN_0803cca4: @ 0x0803CCA4
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r2, _0803CD38 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _0803CD3C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0803CD40 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0xdb
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0803CD44 @ =0x0803C261
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0803CD48 @ =0x000002CA
	adds r0, r5, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0
	str r0, [sp]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803CD38: .4byte 0xFFFF0000
_0803CD3C: .4byte 0x0000FFFF
_0803CD40: .4byte 0x00002001
_0803CD44: .4byte 0x0803C261
_0803CD48: .4byte 0x000002CA

	thumb_func_start FUN_0803cd4c
FUN_0803cd4c: @ 0x0803CD4C
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0x88
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r2, _0803CDE0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x90
	orrs r0, r3
	ldr r1, _0803CDE4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0803CDE8 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0xdb
	lsls r0, r0, #2
	adds r1, r4, r0
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0803CDEC @ =0x0803C261
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r1, _0803CDF0 @ =0x000002CE
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0xc0
	lsls r0, r0, #0xb
	str r0, [sp]
	ldr r0, _0803CDF4 @ =0x000002D2
	adds r4, r4, r0
	movs r3, #0
	ldrsh r0, [r4, r3]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803CDE0: .4byte 0xFFFF0000
_0803CDE4: .4byte 0x0000FFFF
_0803CDE8: .4byte 0x00002001
_0803CDEC: .4byte 0x0803C261
_0803CDF0: .4byte 0x000002CE
_0803CDF4: .4byte 0x000002D2

	thumb_func_start FUN_0803cdf8
FUN_0803cdf8: @ 0x0803CDF8
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r2, _0803CE78 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x60
	orrs r0, r3
	ldr r1, _0803CE7C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0803CE80 @ =0x00004101
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0xdb
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0803CE84 @ =FUN_0803c1c0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	ldr r2, _0803CE88 @ =0x00000802
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_08236514
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803CE78: .4byte 0xFFFF0000
_0803CE7C: .4byte 0x0000FFFF
_0803CE80: .4byte 0x00004101
_0803CE84: .4byte FUN_0803c1c0
_0803CE88: .4byte 0x00000802

	thumb_func_start FUN_0803ce8c
FUN_0803ce8c: @ 0x0803CE8C
	ldr r2, _0803CEC8 @ =0x00000169
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	ldr r3, _0803CECC @ =0x000002B6
	adds r1, r0, r3
	strb r2, [r1]
	subs r3, #0xa
	adds r1, r0, r3
	strh r2, [r1]
	ldr r3, _0803CED0 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _0803CED4 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _0803CED8 @ =0x0203B400
	adds r1, r1, r2
	ldrh r2, [r1]
	ldr r1, _0803CEDC @ =0x03002CF0
	ldr r1, [r1]
	adds r1, r1, r2
	movs r2, #3
	ands r1, r2
	ldr r3, _0803CEE0 @ =0x000002B7
	adds r0, r0, r3
	strb r1, [r0]
	bx lr
	.align 2, 0
_0803CEC8: .4byte 0x00000169
_0803CECC: .4byte 0x000002B6
_0803CED0: .4byte 0x030046B8
_0803CED4: .4byte 0x000003FF
_0803CED8: .4byte 0x0203B400
_0803CEDC: .4byte 0x03002CF0
_0803CEE0: .4byte 0x000002B7

	thumb_func_start FUN_0803cee4
FUN_0803cee4: @ 0x0803CEE4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r7, r6, #0
	adds r4, r6, #0
	adds r4, #0x48
	adds r0, r4, #0
	bl FUN_0823b4b8
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r6, #0
	bl FUN_08022dfc
	movs r5, #0xb2
	lsls r5, r5, #1
	adds r0, r6, r5
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	ldrh r1, [r4, #8]
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	ldrh r5, [r4, #0xa]
	adds r0, r0, r5
	adds r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	ldrh r1, [r4, #0xc]
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	movs r5, #0xb5
	lsls r5, r5, #1
	adds r3, r6, r5
	ldrb r0, [r3]
	cmp r0, #0
	beq _0803CFD8
	ldr r2, _0803CF78 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803CF7C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0803CF80 @ =0x0203B400
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r2, _0803CF84 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldrb r0, [r3]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0803CF88
	asrs r3, r0, #0xc
	b _0803CF8E
	.align 2, 0
_0803CF78: .4byte 0x030046B8
_0803CF7C: .4byte 0x000003FF
_0803CF80: .4byte 0x0203B400
_0803CF84: .4byte 0x085B0A08
_0803CF88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0803CF8E:
	movs r0, #0xdb
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xb5
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0803CFBA
	asrs r2, r0, #0xc
	b _0803CFC0
_0803CFBA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0803CFC0:
	movs r5, #0xdc
	lsls r5, r5, #2
	adds r0, r6, r5
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	movs r0, #0xb5
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0803CFD8:
	adds r0, r7, #0
	bl FUN_08022e20
	adds r2, r7, #0
	adds r2, #0x48
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0803D020
	movs r3, #0
	ldrsh r5, [r1, r3]
	movs r3, #8
	ldrsh r0, [r2, r3]
	subs r5, r5, r0
	movs r0, #4
	ldrsh r4, [r1, r0]
	movs r1, #0xc
	ldrsh r0, [r2, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r1, r7, #0
	adds r1, #0xc8
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0xc0
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0803D020:
	movs r1, #3
	adds r0, r7, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0803D092
	bl FUN_08050d40
	cmp r0, #0
	beq _0803D092
	adds r0, r7, #0
	adds r0, #0x92
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r7, r0, #0x14
	adds r4, r6, #0
	adds r4, #0x90
	movs r2, #0
	ldrsh r5, [r4, r2]
	adds r1, r5, r7
	adds r0, r6, #0
	bl FUN_08022bb0
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r5, r0
	beq _0803D08A
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r0, r6, r5
	ldr r4, _0803D09C @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	movs r3, #0x10
	orrs r1, r3
	ldr r2, _0803D0A0 @ =0x0000FFFF
	ands r1, r2
	str r1, [sp, #8]
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r3
	str r1, [sp, #0xc]
	adds r3, r6, #0
	adds r3, #0x50
	add r1, sp, #8
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r7, #0
	movs r2, #1
	bl FUN_0805fe7c
_0803D08A:
	movs r0, #0xdd
	lsls r0, r0, #2
	bl PlaySound_0824078c
_0803D092:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D09C: .4byte 0xFFFF0000
_0803D0A0: .4byte 0x0000FFFF

	thumb_func_start FUN_0803d0a4
FUN_0803d0a4: @ 0x0803D0A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r5, r7, #0
	adds r6, r7, #0
	adds r6, #0x48
	bl FUN_08022ec0
	adds r0, r7, #0
	bl FUN_0803c8b4
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r3, r7, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _0803D0E0
	movs r2, #4
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
_0803D0E0:
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r4, r7, r1
	movs r2, #4
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0803D100
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	b _0803D120
_0803D100:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldrb r1, [r6, #5]
	ldr r3, _0803D180 @ =0x00000212
	adds r0, r7, r3
	strb r1, [r0]
_0803D120:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r0, #8
	mov r2, sl
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0803D1EC
	movs r3, #0x80
	lsls r3, r3, #0xf
	ands r3, r1
	cmp r3, #0
	beq _0803D18C
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	subs r3, #0x1e
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D15C
	ldr r2, _0803D184 @ =0x000002C6
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	asrs r1, r0, #6
_0803D15C:
	ldr r2, _0803D188 @ =0x000002D6
	adds r0, r5, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0x80
	lsls r0, r0, #0xa
	str r0, [sp]
	movs r3, #0xb7
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	b _0803D1D0
	.align 2, 0
_0803D180: .4byte 0x00000212
_0803D184: .4byte 0x000002C6
_0803D188: .4byte 0x000002D6
_0803D18C:
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _0803D298 @ =0x000002B6
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D1AC
	adds r2, #0x10
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	asrs r1, r0, #6
_0803D1AC:
	ldr r0, _0803D29C @ =0x000002CA
	adds r0, r0, r5
	mov r8, r0
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r8, r0
	str r3, [sp]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r2, r8
	movs r3, #0
	bl FUN_082364f8
_0803D1D0:
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r1, r5, r3
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldrb r0, [r6, #5]
	adds r1, r4, #0
	adds r1, #0x42
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08236400
_0803D1EC:
	movs r0, #0x88
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r1, #0x80
	lsls r1, r1, #0xd
	mov r2, sl
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0803D26A
	ldr r3, _0803D2A0 @ =0x000002CE
	adds r0, r5, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	subs r3, #0x18
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D21E
	ldr r2, _0803D2A4 @ =0x000002C6
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	asrs r1, r0, #6
_0803D21E:
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0xc0
	lsls r0, r0, #0xb
	str r0, [sp]
	ldr r3, _0803D2A8 @ =0x000002D2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	adds r0, r5, #0
	add r1, sp, #8
	bl FUN_0803c274
	adds r0, r4, #0
	add r1, sp, #8
	movs r2, #0
	bl FUN_082364c4
	ldrb r0, [r6, #5]
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	adds r0, #0x40
	ldr r2, _0803D2AC @ =0x00000262
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08236400
_0803D26A:
	movs r1, #0x10
	mov r3, sl
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0803D2B4
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_080139a0
	ldr r1, _0803D2B0 @ =0xFFDFFFFF
	mov r2, sl
	ldr r0, [r2]
	ands r0, r1
	b _0803D2F0
	.align 2, 0
_0803D298: .4byte 0x000002B6
_0803D29C: .4byte 0x000002CA
_0803D2A0: .4byte 0x000002CE
_0803D2A4: .4byte 0x000002C6
_0803D2A8: .4byte 0x000002D2
_0803D2AC: .4byte 0x00000262
_0803D2B0: .4byte 0xFFDFFFFF
_0803D2B4:
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r2, r5, r3
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #9
	mov r2, sl
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0803D2DC
	adds r3, #0x60
	adds r0, r5, r3
	bl FUN_080139a0
	b _0803D2E6
_0803D2DC:
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_08013984
_0803D2E6:
	movs r1, #0x80
	lsls r1, r1, #0xe
	mov r2, sl
	ldr r0, [r2]
	orrs r0, r1
_0803D2F0:
	str r0, [r2]
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _0803D330
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0803D30E
	b _0803D566
_0803D30E:
	adds r0, r5, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	cmp r1, #0
	beq _0803D408
	ldr r0, _0803D32C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r1, r5, r3
	str r0, [r1]
	b _0803D566
	.align 2, 0
_0803D32C: .4byte 0x03003584
_0803D330:
	ldr r0, _0803D390 @ =0x00000818
	adds r0, r0, r5
	mov sb, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803D39C
	adds r0, r5, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	ldr r0, _0803D394 @ =0x03003584
	lsls r1, r1, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldr r3, _0803D398 @ =0x0000081A
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r4, r5, r0
	subs r3, #1
	adds r6, r5, r3
	movs r3, #0
	ldrsb r3, [r6, r3]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl rgb555_08237468
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1e
	bgt _0803D38A
	b _0803D566
_0803D38A:
	movs r0, #0x1f
	strb r0, [r6]
	b _0803D566
	.align 2, 0
_0803D390: .4byte 0x00000818
_0803D394: .4byte 0x03003584
_0803D398: .4byte 0x0000081A
_0803D39C:
	cmp r0, #1
	bne _0803D43C
	adds r0, r5, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	lsls r1, r1, #5
	ldr r3, _0803D418 @ =0x03003584
	ldr r2, [r3]
	adds r1, r2, r1
	ldr r0, _0803D41C @ =0x0000081A
	adds r0, r0, r5
	mov r8, r0
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r4, r5, r3
	ldr r0, _0803D420 @ =0x00000819
	adds r6, r5, r0
	movs r3, #0
	ldrsb r3, [r6, r3]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl rgb555_08237468
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	ldrb r0, [r6]
	subs r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	cmp r0, #0
	ble _0803D3EA
	b _0803D566
_0803D3EA:
	movs r0, #0
	strb r0, [r6]
	movs r0, #0xff
	mov r2, sb
	strb r0, [r2]
	adds r0, r5, #0
	bl FUN_0803c1bc
	mov r3, r8
	strh r0, [r3]
	adds r0, r5, #0
	bl FUN_0803c1bc
	cmp r0, #0
	bne _0803D424
_0803D408:
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0x83
	lsls r2, r2, #3
	adds r0, r5, r2
	str r0, [r1]
	b _0803D566
	.align 2, 0
_0803D418: .4byte 0x03003584
_0803D41C: .4byte 0x0000081A
_0803D420: .4byte 0x00000819
_0803D424:
	lsls r0, r0, #5
	ldr r3, _0803D438 @ =0x03003584
	ldr r1, [r3]
	adds r1, r1, r0
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	b _0803D566
	.align 2, 0
_0803D438: .4byte 0x03003584
_0803D43C:
	cmp r0, #2
	bne _0803D4E8
	adds r0, r5, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	lsls r1, r1, #5
	ldr r3, _0803D4C0 @ =0x03003584
	ldr r2, [r3]
	adds r1, r2, r1
	ldr r0, _0803D4C4 @ =0x0000081A
	adds r0, r0, r5
	mov r8, r0
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r4, r5, r3
	ldr r0, _0803D4C8 @ =0x00000819
	adds r6, r5, r0
	movs r3, #0
	ldrsb r3, [r6, r3]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl rgb555_08237468
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	ldr r2, _0803D4CC @ =0x0000081E
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803D530
	ldrb r0, [r6]
	subs r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0803D566
	movs r0, #0
	strb r0, [r6]
	movs r0, #0xff
	mov r3, sb
	strb r0, [r3]
	adds r0, r5, #0
	bl FUN_0803c1bc
	mov r1, r8
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_0803c1bc
	cmp r0, #0
	bne _0803D4D0
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r3, #0x83
	lsls r3, r3, #3
	adds r0, r5, r3
	str r0, [r1]
	b _0803D566
	.align 2, 0
_0803D4C0: .4byte 0x03003584
_0803D4C4: .4byte 0x0000081A
_0803D4C8: .4byte 0x00000819
_0803D4CC: .4byte 0x0000081E
_0803D4D0:
	lsls r0, r0, #5
	ldr r2, _0803D4E4 @ =0x03003584
	ldr r1, [r2]
	adds r1, r1, r0
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	b _0803D566
	.align 2, 0
_0803D4E4: .4byte 0x03003584
_0803D4E8:
	cmp r0, #3
	bne _0803D566
	adds r0, r5, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	ldr r0, _0803D548 @ =0x03003584
	lsls r1, r1, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldr r3, _0803D54C @ =0x0000081A
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r4, r5, r0
	subs r3, #1
	adds r6, r5, r3
	movs r3, #0
	ldrsb r3, [r6, r3]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl rgb555_08237468
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	ldr r2, _0803D550 @ =0x0000081E
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _0803D554
_0803D530:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1e
	ble _0803D566
	movs r0, #0x1f
	strb r0, [r6]
	movs r0, #1
	strb r0, [r1]
	b _0803D566
	.align 2, 0
_0803D548: .4byte 0x03003584
_0803D54C: .4byte 0x0000081A
_0803D550: .4byte 0x0000081E
_0803D554:
	ldrb r0, [r6]
	subs r0, #1
	movs r2, #0
	strb r0, [r6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0803D566
	strb r2, [r6]
	strb r2, [r1]
_0803D566:
	adds r0, r7, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803D5EE
	movs r1, #0x80
	lsls r1, r1, #0xe
	mov r3, sl
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0803D5E0
	movs r1, #4
	ldr r0, _0803D5D4 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0803D5E0
	ldr r0, _0803D5D8 @ =0x0000081F
	adds r1, r5, r0
	ldrb r4, [r1]
	cmp r4, #0
	bne _0803D5B4
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x15
	movs r2, #0x82
	lsls r2, r2, #4
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _0803D5DC @ =0x00000822
	adds r0, r5, r3
	strh r4, [r0]
_0803D5B4:
	adds r0, r5, #0
	bl FUN_0803c328
	ldr r0, _0803D5DC @ =0x00000822
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x80
	bls _0803D5EE
	movs r0, #0x80
	strh r0, [r1]
	b _0803D5EE
	.align 2, 0
_0803D5D4: .4byte 0x03002BC0
_0803D5D8: .4byte 0x0000081F
_0803D5DC: .4byte 0x00000822
_0803D5E0:
	ldr r2, _0803D614 @ =0x0000081F
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r0, #8
	bl FUN_0823b880
_0803D5EE:
	adds r0, r7, #0
	adds r0, #0xb4
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xe0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D614: .4byte 0x0000081F

	thumb_func_start FUN_0803d618
FUN_0803d618: @ 0x0803D618
	push {lr}
	adds r2, r0, #0
	ldr r1, _0803D640 @ =0x000002C1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D644
	movs r0, #0xa
	adds r3, r2, #0
	adds r3, #0xa6
	movs r1, #0
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r2, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0803D646
	.align 2, 0
_0803D640: .4byte 0x000002C1
_0803D644:
	movs r0, #0
_0803D646:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0803d64c
FUN_0803d64c: @ 0x0803D64C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r5, r7, #0
	ldr r2, _0803D698 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803D69C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_0803d618
	cmp r0, #0
	beq _0803D66E
	b _0803D824
_0803D66E:
	ldr r2, _0803D6A0 @ =0x085AAF2C
	movs r0, #0xab
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r3, _0803D6A4 @ =0x000002B7
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #4
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #6
	bls _0803D68C
	b _0803D7E8
_0803D68C:
	lsls r0, r0, #2
	ldr r1, _0803D6A8 @ =_0803D6AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803D698: .4byte 0x030046B8
_0803D69C: .4byte 0x000003FF
_0803D6A0: .4byte 0x085AAF2C
_0803D6A4: .4byte 0x000002B7
_0803D6A8: .4byte _0803D6AC
_0803D6AC: @ jump table
	.4byte _0803D6C8 @ case 0
	.4byte _0803D72C @ case 1
	.4byte _0803D7A4 @ case 2
	.4byte _0803D7A8 @ case 3
	.4byte _0803D7AC @ case 4
	.4byte _0803D7B0 @ case 5
	.4byte _0803D7C2 @ case 6
_0803D6C8:
	movs r0, #0xa5
	lsls r0, r0, #2
	adds r6, r7, r0
	adds r4, r5, #0
	adds r4, #0x50
	movs r1, #0xc0
	lsls r1, r1, #2
	mov r8, r1
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #6
	mov r3, r8
	bl FUN_0823556c
	movs r3, #0
	ldrsh r2, [r4, r3]
	movs r1, #0
	ldrsh r0, [r6, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	movs r3, #4
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0803D728 @ =0x0000FFFF
	cmp r1, r0
	bgt _0803D71C
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #6
	mov r3, r8
	bl FUN_0823556c
_0803D71C:
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0
	movs r0, #0x40
	b _0803D78A
	.align 2, 0
_0803D728: .4byte 0x0000FFFF
_0803D72C:
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r6, r7, r1
	adds r4, r5, #0
	adds r4, #0x50
	movs r2, #0xc0
	lsls r2, r2, #2
	mov r8, r2
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #4
	mov r3, r8
	bl FUN_0823556c
	movs r3, #0
	ldrsh r2, [r4, r3]
	movs r1, #0
	ldrsh r0, [r6, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	movs r3, #4
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0803D7A0 @ =0x0000FFFF
	cmp r1, r0
	bgt _0803D780
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #4
	mov r3, r8
	bl FUN_0823556c
_0803D780:
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0
	movs r0, #0x20
_0803D78A:
	strh r0, [r1]
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0xa6
	strb r1, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r1, [r0]
	b _0803D7E8
	.align 2, 0
_0803D7A0: .4byte 0x0000FFFF
_0803D7A4:
	movs r0, #7
	b _0803D7D2
_0803D7A8:
	movs r0, #9
	b _0803D7D2
_0803D7AC:
	movs r0, #3
	b _0803D7D2
_0803D7B0:
	adds r0, r5, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x3f
	ble _0803D7BE
	movs r0, #7
	b _0803D7D2
_0803D7BE:
	movs r0, #8
	b _0803D7D2
_0803D7C2:
	adds r0, r5, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x3f
	ble _0803D7D0
	movs r0, #3
	b _0803D7D2
_0803D7D0:
	movs r0, #0xb
_0803D7D2:
	adds r2, r5, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
_0803D7E8:
	movs r2, #0xab
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0803D824
	movs r0, #0
	strh r0, [r1]
	ldr r2, _0803D830 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803D834 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0803D838 @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r0, _0803D83C @ =0x03002CF0
	ldr r0, [r0]
	adds r0, r0, r1
	movs r1, #3
	ands r0, r1
	ldr r2, _0803D840 @ =0x000002B7
	adds r1, r7, r2
	strb r0, [r1]
_0803D824:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D830: .4byte 0x030046B8
_0803D834: .4byte 0x000003FF
_0803D838: .4byte 0x0203B400
_0803D83C: .4byte 0x03002CF0
_0803D840: .4byte 0x000002B7

	thumb_func_start FUN_0803d844
FUN_0803d844: @ 0x0803D844
	push {r4, lr}
	adds r3, r0, #0
	adds r0, #0x90
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _0803D884
	adds r0, r3, #0
	adds r0, #0x96
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D884
	movs r2, #2
	adds r1, r3, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _0803D8B4 @ =FUN_080400a4
	movs r0, #0xe
	movs r4, #0xa3
	movs r1, #0
	strb r0, [r4, r3]
	adds r0, r3, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_0803D884:
	adds r0, r3, #0
	adds r0, #0x96
	movs r2, #0
	strb r2, [r0]
	movs r1, #2
	adds r0, #2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0803D8B8
	movs r1, #1
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r1, [r0]
	b _0803D8DA
	.align 2, 0
_0803D8B4: .4byte FUN_080400a4
_0803D8B8:
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	bne _0803D8C4
	movs r0, #0
	b _0803D8DC
_0803D8C4:
	adds r0, r3, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
_0803D8DA:
	movs r0, #1
_0803D8DC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0803d8e4
FUN_0803d8e4: @ 0x0803D8E4
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803D908
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r0, #1
	b _0803D90A
_0803D908:
	movs r0, #0
_0803D90A:
	adds r1, r0, #0
	cmp r1, #1
	bne _0803D916
	adds r0, r3, #0
	adds r0, #0xa2
	strb r1, [r0]
_0803D916:
	adds r3, #0xbc
	ldr r1, _0803D92C @ =0x0000081C
	adds r0, r2, r1
	ldr r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	bls _0803D930
	adds r0, r2, #0
	bl FUN_0803d64c
	b _0803D934
	.align 2, 0
_0803D92C: .4byte 0x0000081C
_0803D930:
	adds r0, r1, #1
	str r0, [r3]
_0803D934:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803d93c
FUN_0803d93c: @ 0x0803D93C
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803D962
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0803D968
_0803D962:
	movs r1, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0803D968:
	cmp r1, #0
	beq _0803D974
	movs r0, #2
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0803D974:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803D9A4
	movs r2, #0xa
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803D9A0 @ =0x0000081C
	adds r0, r3, r1
	strh r2, [r0]
	b _0803D9AE
	.align 2, 0
_0803D9A0: .4byte 0x0000081C
_0803D9A4:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803D9AE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803d9b4
FUN_0803d9b4: @ 0x0803D9B4
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803D9DA
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0803D9E0
_0803D9DA:
	movs r1, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0803D9E0:
	cmp r1, #0
	beq _0803D9EC
	movs r0, #3
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0803D9EC:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803DA1C
	movs r2, #0xf
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803DA18 @ =0x0000081C
	adds r0, r3, r1
	strh r2, [r0]
	b _0803DA26
	.align 2, 0
_0803DA18: .4byte 0x0000081C
_0803DA1C:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DA26:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803da2c
FUN_0803da2c: @ 0x0803DA2C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803DA50
	strb r3, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r3, [r0]
	movs r1, #1
	adds r3, r0, #0
	b _0803DA56
_0803DA50:
	movs r1, #0
	adds r3, r2, #0
	adds r3, #0xa7
_0803DA56:
	cmp r1, #0
	beq _0803DA62
	movs r0, #4
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0803DA62:
	ldrb r0, [r3]
	cmp r0, #0
	beq _0803DA82
	movs r0, #4
	adds r3, r2, #0
	adds r3, #0xa6
	movs r1, #0
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r2, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0803DA8C
_0803DA82:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DA8C:
	pop {r0}
	bx r0

	thumb_func_start FUN_0803da90
FUN_0803da90: @ 0x0803DA90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r6, r0, #0
	mov r8, r6
	adds r5, r6, #0
	adds r5, #0x48
	adds r1, r6, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803DABE
	strb r2, [r1]
	adds r0, r6, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r0, #1
	b _0803DAC0
_0803DABE:
	movs r0, #0
_0803DAC0:
	cmp r0, #0
	beq _0803DAD6
	movs r0, #5
	adds r2, r6, #0
	adds r2, #0xa2
	movs r1, #0
	strb r0, [r2]
	movs r0, #0xad
	lsls r0, r0, #2
	add r0, r8
	strb r1, [r0]
_0803DAD6:
	mov r3, sp
	ldrb r4, [r5, #5]
	movs r7, #0xc8
	ldr r2, _0803DAF8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0803DAFC
	asrs r1, r0, #0xc
	b _0803DB02
	.align 2, 0
_0803DAF8: .4byte 0x085B0A08
_0803DAFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803DB02:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0803DB1A
	asrs r0, r0, #0xc
	b _0803DB20
_0803DB1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803DB20:
	strh r0, [r3, #4]
	mov r4, sp
	mov r1, sp
	ldrh r0, [r5, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r3, [r5, #0xa]
	adds r0, r0, r3
	strh r0, [r4, #2]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	ldr r5, _0803DBBC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r5
	ldr r2, _0803DBC0 @ =0x0000FF38
	orrs r0, r2
	str r0, [sp, #8]
	add r1, sp, #8
	ldr r0, [r1, #4]
	ands r0, r5
	orrs r0, r2
	str r0, [r1, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r4, #4]
	ldrh r3, [r1, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
	ldr r0, [sp, #0x10]
	ands r0, r5
	movs r3, #0xc8
	orrs r0, r3
	str r0, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r5
	orrs r0, r3
	str r0, [r2, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	ldrh r0, [r2, #2]
	ldrh r3, [r4, #2]
	adds r0, r0, r3
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r3, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	mov r0, r8
	bl FUN_0803c6a0
	cmp r0, #0
	blt _0803DBC4
	movs r0, #5
	adds r1, r6, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r1, #0x16
	movs r0, #0
	str r0, [r1]
	subs r1, #0x14
	b _0803DD5E
	.align 2, 0
_0803DBBC: .4byte 0xFFFF0000
_0803DBC0: .4byte 0x0000FF38
_0803DBC4:
	movs r0, #0xc8
	lsls r0, r0, #1
	mov ip, r0
	mov r4, r8
	adds r4, #0x48
	add r3, sp, #0x18
	ldrb r5, [r4, #5]
	ldr r2, _0803DBF4 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	adds r7, r3, #0
	cmp r0, #0
	blt _0803DBF8
	asrs r1, r0, #0xc
	b _0803DBFE
	.align 2, 0
_0803DBF4: .4byte 0x085B0A08
_0803DBF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803DBFE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0803DC1A
	asrs r0, r0, #0xc
	b _0803DC20
_0803DC1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803DC20:
	strh r0, [r3, #4]
	add r1, sp, #0x18
	ldrh r0, [r4, #8]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r7, #2]
	ldrh r3, [r4, #0xa]
	adds r0, r0, r3
	strh r0, [r7, #2]
	ldrh r1, [r4, #0xc]
	ldrh r0, [r7, #4]
	adds r1, r1, r0
	strh r1, [r7, #4]
	adds r5, r7, #0
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0803DC60
	cmp r1, #0
	blt _0803DC60
	ldr r0, _0803DC64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0803DC60
	ldr r0, _0803DC68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0803DC6C
_0803DC60:
	movs r4, #0
	b _0803DC7A
	.align 2, 0
_0803DC64: .4byte 0x030046A8
_0803DC68: .4byte 0x030046AC
_0803DC6C:
	ldr r0, _0803DC8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0803DC7A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0803DC90
	adds r0, #4
	b _0803DC9C
	.align 2, 0
_0803DC8C: .4byte 0x030046A4
_0803DC90:
	ldr r0, _0803DCB0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0803DC9C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0803DCB4
	cmp r2, #2
	beq _0803DCB8
	b _0803DCBC
	.align 2, 0
_0803DCB0: .4byte 0x030046A4
_0803DCB4:
	ldrb r0, [r5, #4]
	b _0803DCBA
_0803DCB8:
	ldrb r0, [r5]
_0803DCBA:
	subs r1, r1, r0
_0803DCBC:
	adds r5, r1, #0
	add r0, sp, #0x18
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0803DCE4
	cmp r1, #0
	blt _0803DCE4
	ldr r0, _0803DCE8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0803DCE4
	ldr r0, _0803DCEC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0803DCF0
_0803DCE4:
	movs r4, #0
	b _0803DCFE
	.align 2, 0
_0803DCE8: .4byte 0x030046A8
_0803DCEC: .4byte 0x030046AC
_0803DCF0:
	ldr r0, _0803DD10 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0803DCFE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0803DD14
	adds r0, #4
	b _0803DD20
	.align 2, 0
_0803DD10: .4byte 0x030046A4
_0803DD14:
	ldr r0, _0803DD64 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0803DD20:
	ldrh r2, [r0, #2]
	movs r0, #0xb2
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r0, r5, r0
	ldr r3, _0803DD68 @ =0x000001FF
	adds r0, r0, r3
	ldr r1, _0803DD6C @ =0x000002FE
	cmp r0, r1
	bhi _0803DD4A
	movs r0, #2
	ands r2, r0
	cmp r2, #0
	bne _0803DD4A
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803DD70
_0803DD4A:
	movs r0, #6
	adds r2, r6, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r6, #0
	adds r1, #0xa8
_0803DD5E:
	movs r0, #1
	strb r0, [r1]
	b _0803DD7A
	.align 2, 0
_0803DD64: .4byte 0x030046A4
_0803DD68: .4byte 0x000001FF
_0803DD6C: .4byte 0x000002FE
_0803DD70:
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DD7A:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803dd88
FUN_0803dd88: @ 0x0803DD88
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803DDAE
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0803DDB4
_0803DDAE:
	movs r1, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0803DDB4:
	cmp r1, #0
	beq _0803DDC0
	movs r0, #6
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0803DDC0:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803DDF0
	movs r2, #0xf
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803DDEC @ =0x0000081C
	adds r0, r3, r1
	strh r2, [r0]
	b _0803DDFA
	.align 2, 0
_0803DDEC: .4byte 0x0000081C
_0803DDF0:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DDFA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803de00
FUN_0803de00: @ 0x0803DE00
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803DE26
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0803DE2C
_0803DE26:
	movs r1, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0803DE2C:
	cmp r1, #0
	beq _0803DE38
	movs r0, #7
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0803DE38:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803DE68
	movs r2, #0xa
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803DE64 @ =0x0000081C
	adds r0, r3, r1
	strh r2, [r0]
	b _0803DE72
	.align 2, 0
_0803DE64: .4byte 0x0000081C
_0803DE68:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DE72:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803de78
FUN_0803de78: @ 0x0803DE78
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803DE9E
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0803DEA4
_0803DE9E:
	movs r1, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0803DEA4:
	cmp r1, #0
	beq _0803DEB0
	movs r0, #8
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0803DEB0:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803DEE0
	movs r2, #0xa
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803DEDC @ =0x0000081C
	adds r0, r3, r1
	strh r2, [r0]
	b _0803DEEA
	.align 2, 0
_0803DEDC: .4byte 0x0000081C
_0803DEE0:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DEEA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803def0
FUN_0803def0: @ 0x0803DEF0
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803DF16
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0803DF1C
_0803DF16:
	movs r1, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0803DF1C:
	cmp r1, #0
	beq _0803DF28
	movs r0, #9
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0803DF28:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803DF58
	movs r2, #0xa
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803DF54 @ =0x0000081C
	adds r0, r3, r1
	strh r2, [r0]
	b _0803DF62
	.align 2, 0
_0803DF54: .4byte 0x0000081C
_0803DF58:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DF62:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803df68
FUN_0803df68: @ 0x0803DF68
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803DF8E
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0803DF94
_0803DF8E:
	movs r1, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0803DF94:
	cmp r1, #0
	beq _0803DFA0
	movs r0, #0xa
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0803DFA0:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803DFD0
	movs r2, #0xa
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803DFCC @ =0x0000081C
	adds r0, r3, r1
	strh r2, [r0]
	b _0803DFDA
	.align 2, 0
_0803DFCC: .4byte 0x0000081C
_0803DFD0:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DFDA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803dfe0
FUN_0803dfe0: @ 0x0803DFE0
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803E006
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0803E00C
_0803E006:
	movs r1, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0803E00C:
	cmp r1, #0
	beq _0803E018
	movs r0, #0xb
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0803E018:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803E048
	movs r2, #0xa
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803E044 @ =0x0000081C
	adds r0, r3, r1
	strh r2, [r0]
	b _0803E052
	.align 2, 0
_0803E044: .4byte 0x0000081C
_0803E048:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E052:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803e058
FUN_0803e058: @ 0x0803E058
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r4, r7, #0
	adds r1, r7, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803E084
	strb r2, [r1]
	adds r0, r7, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r1, #1
	adds r5, r0, #0
	b _0803E08A
_0803E084:
	movs r1, #0
	adds r5, r7, #0
	adds r5, #0xa7
_0803E08A:
	adds r3, r1, #0
	cmp r3, #1
	bne _0803E146
	movs r0, #4
	adds r1, r7, #0
	adds r1, #0xa2
	strb r0, [r1]
	ldr r2, _0803E0F0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803E0F4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0803E0F8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #8
	movs r1, #3
	ands r0, r1
	ldr r2, _0803E0FC @ =0x000002B3
	adds r1, r4, r2
	strb r0, [r1]
	movs r6, #0xb6
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrh r1, [r0]
	subs r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	subs r6, #0x24
	adds r0, r4, r6
	strb r3, [r0]
	movs r0, #3
	movs r2, #0xb
	ldr r3, _0803E100 @ =0x00000818
	adds r1, r4, r3
	strb r0, [r1]
	ldr r6, _0803E104 @ =0x0000081A
	adds r0, r4, r6
	movs r3, #0
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _0803E10C
	ldr r0, _0803E108 @ =0x00000819
	adds r1, r4, r0
	movs r0, #0x1f
	strb r0, [r1]
	b _0803E136
	.align 2, 0
_0803E0F0: .4byte 0x030046B8
_0803E0F4: .4byte 0x000003FF
_0803E0F8: .4byte 0x0203B400
_0803E0FC: .4byte 0x000002B3
_0803E100: .4byte 0x00000818
_0803E104: .4byte 0x0000081A
_0803E108: .4byte 0x00000819
_0803E10C:
	cmp r0, #0
	bne _0803E11C
	ldr r1, _0803E118 @ =0x00000819
	adds r0, r4, r1
	b _0803E134
	.align 2, 0
_0803E118: .4byte 0x00000819
_0803E11C:
	cmp r0, #2
	bne _0803E12C
	ldr r2, _0803E128 @ =0x00000819
	adds r0, r4, r2
	b _0803E134
	.align 2, 0
_0803E128: .4byte 0x00000819
_0803E12C:
	cmp r0, #3
	bne _0803E136
	ldr r6, _0803E18C @ =0x00000819
	adds r0, r4, r6
_0803E134:
	strb r3, [r0]
_0803E136:
	ldr r0, _0803E190 @ =0x0000081E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _0803E194 @ =0x000002B5
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
_0803E146:
	ldrb r0, [r5]
	movs r3, #0xa3
	adds r3, r3, r7
	mov r8, r3
	cmp r0, #0
	beq _0803E154
	b _0803E2F2
_0803E154:
	ldrb r0, [r3]
	cmp r0, #5
	beq _0803E15C
	b _0803E4DC
_0803E15C:
	movs r6, #0xc8
	lsls r6, r6, #1
	mov ip, r6
	adds r3, r4, #0
	adds r3, #0x48
	mov r5, sp
	ldrb r6, [r3, #5]
	ldr r2, _0803E198 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0803E19C
	asrs r1, r0, #0xc
	b _0803E1A2
	.align 2, 0
_0803E18C: .4byte 0x00000819
_0803E190: .4byte 0x0000081E
_0803E194: .4byte 0x000002B5
_0803E198: .4byte 0x085B0A08
_0803E19C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803E1A2:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r6, ip
	muls r6, r0, r6
	adds r0, r6, #0
	cmp r0, #0
	blt _0803E1BE
	asrs r0, r0, #0xc
	b _0803E1C4
_0803E1BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803E1C4:
	strh r0, [r5, #4]
	mov r2, sp
	mov r1, sp
	ldrh r0, [r3, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #0xa]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r3, #0xc]
	ldrh r3, [r2, #4]
	adds r1, r1, r3
	strh r1, [r2, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0803E20A
	cmp r1, #0
	blt _0803E20A
	ldr r0, _0803E210 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0803E20A
	ldr r0, _0803E214 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0803E218
_0803E20A:
	movs r5, #0
	b _0803E226
	.align 2, 0
_0803E210: .4byte 0x030046A8
_0803E214: .4byte 0x030046AC
_0803E218:
	ldr r0, _0803E238 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0803E226:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0803E23C
	adds r0, #4
	b _0803E248
	.align 2, 0
_0803E238: .4byte 0x030046A4
_0803E23C:
	ldr r0, _0803E25C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0803E248:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0803E260
	cmp r2, #2
	beq _0803E264
	b _0803E268
	.align 2, 0
_0803E25C: .4byte 0x030046A4
_0803E260:
	ldrb r0, [r6, #4]
	b _0803E266
_0803E264:
	ldrb r0, [r6]
_0803E266:
	subs r1, r1, r0
_0803E268:
	adds r6, r1, #0
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0803E292
	cmp r1, #0
	blt _0803E292
	ldr r0, _0803E298 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0803E292
	ldr r0, _0803E29C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0803E2A0
_0803E292:
	movs r5, #0
	b _0803E2AE
	.align 2, 0
_0803E298: .4byte 0x030046A8
_0803E29C: .4byte 0x030046AC
_0803E2A0:
	ldr r0, _0803E2C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0803E2AE:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0803E2C4
	adds r0, #4
	b _0803E2D0
	.align 2, 0
_0803E2C0: .4byte 0x030046A4
_0803E2C4:
	ldr r0, _0803E304 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0803E2D0:
	ldrh r2, [r0, #2]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r0, r6, r0
	ldr r6, _0803E308 @ =0x000001FF
	adds r0, r0, r6
	ldr r1, _0803E30C @ =0x000002FE
	cmp r0, r1
	bhi _0803E2F2
	movs r0, #2
	ands r2, r0
	cmp r2, #0
	bne _0803E2F2
	b _0803E4DC
_0803E2F2:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #4
	beq _0803E2FE
	cmp r0, #2
	bne _0803E310
_0803E2FE:
	movs r0, #5
	b _0803E39A
	.align 2, 0
_0803E304: .4byte 0x030046A4
_0803E308: .4byte 0x000001FF
_0803E30C: .4byte 0x000002FE
_0803E310:
	cmp r0, #5
	beq _0803E316
	b _0803E444
_0803E316:
	ldr r2, _0803E350 @ =0x000002B2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803E3B0
	ldr r3, _0803E354 @ =0x000002B5
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803E398
	movs r0, #1
	movs r2, #0xb
	ldr r6, _0803E358 @ =0x00000818
	adds r1, r4, r6
	strb r0, [r1]
	ldr r3, _0803E35C @ =0x0000081A
	adds r0, r4, r3
	movs r3, #0
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _0803E360
	adds r6, #1
	adds r1, r4, r6
	movs r0, #0x1f
	strb r0, [r1]
	b _0803E38A
	.align 2, 0
_0803E350: .4byte 0x000002B2
_0803E354: .4byte 0x000002B5
_0803E358: .4byte 0x00000818
_0803E35C: .4byte 0x0000081A
_0803E360:
	cmp r0, #0
	bne _0803E370
	ldr r1, _0803E36C @ =0x00000819
	adds r0, r4, r1
	b _0803E388
	.align 2, 0
_0803E36C: .4byte 0x00000819
_0803E370:
	cmp r0, #2
	bne _0803E380
	ldr r2, _0803E37C @ =0x00000819
	adds r0, r4, r2
	b _0803E388
	.align 2, 0
_0803E37C: .4byte 0x00000819
_0803E380:
	cmp r0, #3
	bne _0803E38A
	ldr r6, _0803E3A4 @ =0x00000819
	adds r0, r4, r6
_0803E388:
	strb r3, [r0]
_0803E38A:
	ldr r1, _0803E3A8 @ =0x0000081E
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0803E3AC @ =0x000002B5
	adds r0, r4, r2
	strb r1, [r0]
_0803E398:
	movs r0, #7
_0803E39A:
	adds r1, r7, #0
	adds r1, #0xa2
	strb r0, [r1]
	b _0803E4DC
	.align 2, 0
_0803E3A4: .4byte 0x00000819
_0803E3A8: .4byte 0x0000081E
_0803E3AC: .4byte 0x000002B5
_0803E3B0:
	add r0, sp, #8
	adds r1, r7, #0
	adds r1, #0x50
	movs r2, #4
	bl FUN_08235178
	adds r3, r0, #0
	ldr r5, _0803E3EC @ =0x030046B8
	ldr r0, [r5]
	adds r1, r0, #1
	ldr r2, _0803E3F0 @ =0x000003FF
	ands r1, r2
	str r1, [r5]
	lsls r0, r1, #1
	ldr r6, _0803E3F4 @ =0x0203B400
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _0803E3F8
	adds r0, r1, #1
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	subs r2, r3, #2
	movs r1, #1
	ands r0, r1
	subs r3, r2, r0
	b _0803E40E
	.align 2, 0
_0803E3EC: .4byte 0x030046B8
_0803E3F0: .4byte 0x000003FF
_0803E3F4: .4byte 0x0203B400
_0803E3F8:
	adds r0, r1, #1
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _0803E43C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r3, #2
	movs r1, #1
	ands r0, r1
	adds r3, r2, r0
_0803E40E:
	movs r2, #7
	movs r6, #0xa5
	lsls r6, r6, #2
	adds r0, r4, r6
	ands r2, r3
	movs r1, #4
	bl FUN_08234f90
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	movs r0, #2
	adds r1, r7, #0
	adds r1, #0xa2
	strb r0, [r1]
	ldr r2, _0803E440 @ =0x000002B2
	adds r1, r4, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _0803E4DC
	.align 2, 0
_0803E43C: .4byte 0x0203B400
_0803E440: .4byte 0x000002B2
_0803E444:
	cmp r0, #7
	bne _0803E4DC
	ldr r3, _0803E484 @ =0x0000081E
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	ldr r6, _0803E488 @ =0x00000819
	adds r0, r4, r6
	strb r1, [r0]
	ldr r0, _0803E48C @ =0x00000818
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0803c1bc
	ldr r2, _0803E490 @ =0x0000081A
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	cmp r1, #0
	bne _0803E494
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r6, #0x83
	lsls r6, r6, #3
	adds r0, r4, r6
	b _0803E4A2
	.align 2, 0
_0803E484: .4byte 0x0000081E
_0803E488: .4byte 0x00000819
_0803E48C: .4byte 0x00000818
_0803E490: .4byte 0x0000081A
_0803E494:
	ldr r0, _0803E4D4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r1, r4, r2
_0803E4A2:
	str r0, [r1]
	movs r2, #0xf
	movs r1, #0
	adds r0, r4, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r3, _0803E4D8 @ =0x0000081C
	adds r0, r4, r3
	movs r1, #0
	strh r2, [r0]
	movs r6, #0xad
	lsls r6, r6, #2
	adds r0, r4, r6
	strb r1, [r0]
	b _0803E4E6
	.align 2, 0
_0803E4D4: .4byte 0x03003584
_0803E4D8: .4byte 0x0000081C
_0803E4DC:
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E4E6:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803e4f4
FUN_0803e4f4: @ 0x0803E4F4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803E512
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	adds r6, r1, #0
	b _0803E518
_0803E512:
	movs r0, #0
	adds r6, r4, #0
	adds r6, #0xa7
_0803E518:
	cmp r0, #0
	beq _0803E538
	movs r0, #0xc
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	adds r1, #0x50
	movs r3, #0x80
	lsls r3, r3, #1
	movs r2, #4
	bl FUN_08235408
_0803E538:
	ldrb r0, [r6]
	cmp r0, #0
	beq _0803E568
	movs r2, #0xa
	movs r1, #0
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803E564 @ =0x0000081C
	adds r0, r5, r1
	strh r2, [r0]
	b _0803E572
	.align 2, 0
_0803E564: .4byte 0x0000081C
_0803E568:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E572:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803e578
FUN_0803e578: @ 0x0803E578
	push {r4, lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803E592
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0803E594
_0803E592:
	movs r0, #0
_0803E594:
	cmp r0, #0
	beq _0803E5A0
	movs r0, #0xd
	adds r1, r3, #0
	adds r1, #0xa2
	strb r0, [r1]
_0803E5A0:
	movs r4, #1
	adds r0, r3, #0
	adds r0, #0x98
	ldr r2, [r0]
	ands r2, r4
	cmp r2, #0
	bne _0803E5C6
	movs r1, #0xc
	adds r0, #0xc
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r4, [r0]
	b _0803E5D0
_0803E5C6:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E5D0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803e5d8
FUN_0803e5d8: @ 0x0803E5D8
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803E5EE
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
_0803E5EE:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0

	thumb_func_start FUN_0803e5fc
FUN_0803e5fc: @ 0x0803E5FC
	push {lr}
	ldr r2, _0803E614 @ =0x085AAF6C
	adds r1, r0, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0803E614: .4byte 0x085AAF6C

	thumb_func_start FUN_0803e618
FUN_0803e618: @ 0x0803E618
	push {lr}
	ldr r2, _0803E630 @ =0x085AAFA0
	adds r1, r0, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0803E630: .4byte 0x085AAFA0

	thumb_func_start FUN_0803e634
FUN_0803e634: @ 0x0803E634
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #4
	ldr r0, _0803E668 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0803E662
	adds r0, r4, #0
	bl FUN_0803d844
	cmp r0, #0
	bne _0803E662
	ldr r0, _0803E66C @ =0x085AAFA8
	adds r1, r4, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0803E662:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803E668: .4byte 0x03002BC0
_0803E66C: .4byte 0x085AAFA8

	thumb_func_start FUN_0803e670
FUN_0803e670: @ 0x0803E670
	push {lr}
	ldr r2, _0803E688 @ =0x085AAFAC
	adds r1, r0, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0803E688: .4byte 0x085AAFAC

	thumb_func_start FUN_0803e68c
FUN_0803e68c: @ 0x0803E68C
	push {lr}
	adds r2, r0, #0
	adds r2, #0x9d
	movs r1, #0
	strb r1, [r2]
	ldr r2, _0803E6AC @ =0x085AAFB0
	adds r1, r0, #0
	adds r1, #0xa4
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0803E6AC: .4byte 0x085AAFB0

	thumb_func_start FUN_0803e6b0
FUN_0803e6b0: @ 0x0803E6B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	mov sl, r1
	adds r6, r4, #0
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803E726
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_08022d24
	b _0803E742
_0803E726:
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_08022d24
_0803E742:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803E850
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	cmp r0, #0
	bne _0803E850
	movs r2, #0xb0
	lsls r2, r2, #2
	adds r7, r6, r2
	ldrb r0, [r7]
	cmp r0, #0
	beq _0803E7F0
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #3
	movs r1, #0
	bl FUN_08050e2c
	adds r0, r4, #0
	adds r0, #0x92
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r7]
	muls r0, r1, r0
	movs r1, #0x10
	bl Div
	mov r8, r0
	adds r4, r6, #0
	adds r4, #0x90
	movs r3, #0
	ldrsh r5, [r4, r3]
	adds r1, r5, r0
	adds r0, r6, #0
	bl FUN_08022bb0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r5, r0
	beq _0803E7E4
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r4, _0803E828 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	movs r3, #0x10
	orrs r1, r3
	ldr r2, _0803E82C @ =0x0000FFFF
	ands r1, r2
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r3
	str r1, [sp, #0x10]
	adds r3, r6, #0
	adds r3, #0x50
	add r1, sp, #0xc
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	mov r1, r8
	movs r2, #1
	bl FUN_0805fe7c
_0803E7E4:
	mov r2, sb
	strb r2, [r7]
	movs r0, #0xdd
	lsls r0, r0, #2
	bl PlaySound_0824078c
_0803E7F0:
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803E806
	adds r0, r2, #2
	strh r0, [r3]
_0803E806:
	ldr r2, _0803E830 @ =0x085B0A08
	mov r1, sl
	lsls r0, r1, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803E834
	asrs r1, r0, #0xc
	b _0803E83A
	.align 2, 0
_0803E828: .4byte 0xFFFF0000
_0803E82C: .4byte 0x0000FFFF
_0803E830: .4byte 0x085B0A08
_0803E834:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803E83A:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0803E850
	movs r0, #0
	strh r0, [r1]
_0803E850:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803e860
FUN_0803e860: @ 0x0803E860
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r4, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803E8EE
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r4, r3
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08022d24
	adds r0, r4, #0
	bl FUN_0803c590
	movs r0, #0xa5
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r2, [r0]
	adds r0, r4, #0
	bl FUN_0803c4d4
	movs r0, #0xd2
	lsls r0, r0, #2
	bl PlaySound_0824078c
	b _0803E90A
_0803E8EE:
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08022d24
_0803E90A:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803E9EC
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803E9EC
	movs r2, #0xb1
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803E946
	adds r0, r2, #2
	strh r0, [r3]
_0803E946:
	ldr r2, _0803E964 @ =0x085B0A08
	lsls r0, r6, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803E968
	asrs r1, r0, #0xc
	b _0803E96E
	.align 2, 0
_0803E964: .4byte 0x085B0A08
_0803E968:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803E96E:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0803E984
	movs r0, #0
	strh r0, [r1]
_0803E984:
	ldr r1, _0803E9B0 @ =0x00000824
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _0803E9BE
	movs r2, #0xad
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803E9B4
	adds r0, r4, #0
	adds r0, #0xa6
	ldrb r0, [r0]
	cmp r0, #0xb
	bne _0803E9B4
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	bl FUN_0803c78c
	b _0803E9BE
	.align 2, 0
_0803E9B0: .4byte 0x00000824
_0803E9B4:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0803c78c
_0803E9BE:
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r2, _0803E9E0 @ =0x0000028A
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0803E9E4
	adds r0, r5, #0
	bl FUN_0803c5d0
	adds r0, r5, #0
	bl FUN_0803c660
	b _0803E9EC
	.align 2, 0
_0803E9E0: .4byte 0x0000028A
_0803E9E4:
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803E9EC:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803e9f4
FUN_0803e9f4: @ 0x0803E9F4
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803EA2A
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0xb
	bl FUN_08022c9c
	ldr r0, _0803EA90 @ =0x0000034B
	bl PlaySound_0824078c
_0803EA2A:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EA86
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EA86
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0803EA70
	movs r2, #0x80
	lsls r2, r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0803EA70:
	ldr r1, _0803EA94 @ =0x00000369
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803EA86
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803EA86:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EA90: .4byte 0x0000034B
_0803EA94: .4byte 0x00000369

	thumb_func_start FUN_0803ea98
FUN_0803ea98: @ 0x0803EA98
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r5, r4, #0
	adds r5, #0x48
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803EB06
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x13
	bl FUN_08022c9c
	b _0803EB22
_0803EB06:
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x13
	bl FUN_08022c9c
_0803EB22:
	movs r2, #8
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EBBA
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EBBA
	cmp r7, #0x3f
	bgt _0803EBB2
	movs r0, #0x40
	subs r0, r0, r7
	asrs r0, r0, #3
	adds r3, r5, #0
	adds r3, #0x10
	ldrb r5, [r5, #5]
	rsbs r6, r0, #0
	ldr r2, _0803EB84 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803EB88
	asrs r1, r0, #0xc
	b _0803EB8E
	.align 2, 0
_0803EB84: .4byte 0x085B0A08
_0803EB88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803EB8E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803EBA6
	asrs r0, r0, #0xc
	b _0803EBAC
_0803EBA6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803EBAC:
	strh r0, [r3, #4]
	cmp r7, #0x3f
	ble _0803EBBA
_0803EBB2:
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803EBBA:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803ebc4
FUN_0803ebc4: @ 0x0803EBC4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	mov r8, r1
	adds r7, r4, #0
	adds r5, r4, #0
	adds r5, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803EC08
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #9
	bl FUN_08022c9c
	ldr r0, _0803EC18 @ =0x0000034A
	bl PlaySound_0824078c
_0803EC08:
	adds r0, r4, #0
	adds r0, #0xa6
	ldrb r0, [r0]
	cmp r0, #0xb
	bne _0803EC1C
	movs r2, #0x80
	lsls r2, r2, #0xf
	b _0803EC1E
	.align 2, 0
_0803EC18: .4byte 0x0000034A
_0803EC1C:
	movs r2, #8
_0803EC1E:
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803EC3C
	b _0803ED34
_0803EC3C:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803ED34
	movs r1, #0xad
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803ECA8
	adds r1, #0x26
	adds r0, r7, r1
	adds r3, r5, #0
	adds r3, #0x10
	ldrb r5, [r5, #5]
	movs r1, #0
	ldrsh r6, [r0, r1]
	ldr r2, _0803EC88 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803EC8C
	asrs r1, r0, #0xc
	b _0803EC92
	.align 2, 0
_0803EC88: .4byte 0x085B0A08
_0803EC8C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803EC92:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	bge _0803ECEA
	b _0803ECEE
_0803ECA8:
	adds r3, r5, #0
	adds r3, #0x10
	ldrb r5, [r5, #5]
	movs r6, #0x28
	ldr r2, _0803ECCC @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803ECD0
	asrs r1, r0, #0xc
	b _0803ECD6
	.align 2, 0
_0803ECCC: .4byte 0x085B0A08
_0803ECD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803ECD6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803ECEE
_0803ECEA:
	asrs r0, r0, #0xc
	b _0803ECF4
_0803ECEE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803ECF4:
	strh r0, [r3, #4]
	ldr r1, _0803ED18 @ =0x00000824
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _0803ED26
	movs r1, #0xad
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803ED1C
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0
	bl FUN_0803c78c
	b _0803ED26
	.align 2, 0
_0803ED18: .4byte 0x00000824
_0803ED1C:
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0803c78c
_0803ED26:
	mov r0, r8
	cmp r0, #0x9f
	ble _0803ED34
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803ED34:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803ed40
FUN_0803ed40: @ 0x0803ED40
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	mov r8, r4
	adds r5, r4, #0
	adds r5, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803ED84
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0xb
	bl FUN_08022c9c
	ldr r0, _0803EDF8 @ =0x0000034B
	bl PlaySound_0824078c
_0803ED84:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EE40
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EE40
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0803EDCA
	movs r2, #0x80
	lsls r2, r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0803EDCA:
	cmp r7, #9
	bgt _0803EE26
	movs r0, #0xa
	subs r0, r0, r7
	adds r3, r4, #0
	adds r3, #0x58
	ldrb r5, [r5, #5]
	lsls r6, r0, #2
	ldr r2, _0803EDFC @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803EE00
	asrs r1, r0, #0xc
	b _0803EE06
	.align 2, 0
_0803EDF8: .4byte 0x0000034B
_0803EDFC: .4byte 0x085B0A08
_0803EE00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803EE06:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803EE1E
	asrs r0, r0, #0xc
	b _0803EE24
_0803EE1E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803EE24:
	strh r0, [r3, #4]
_0803EE26:
	ldr r0, _0803EE4C @ =0x00000369
	add r0, r8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803EE40
	cmp r7, #0x3b
	ble _0803EE40
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803EE40:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803EE4C: .4byte 0x00000369

	thumb_func_start FUN_0803ee50
FUN_0803ee50: @ 0x0803EE50
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	mov r8, r1
	adds r7, r4, #0
	adds r5, r4, #0
	adds r5, #0x48
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r3, r4, r0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803EEAE
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	ands r0, r1
	lsrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r2, r4, r1
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r1, r3, #0
	movs r3, #0x15
	bl FUN_08022c9c
_0803EEAE:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EF74
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EF74
	mov r0, r8
	cmp r0, #0x13
	bgt _0803EF66
	movs r0, #0x14
	adds r3, r4, #0
	adds r3, #0x58
	ldrb r5, [r5, #5]
	mov r1, r8
	subs r6, r0, r1
	ldr r2, _0803EF04 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803EF08
	asrs r1, r0, #0xc
	b _0803EF0E
	.align 2, 0
_0803EF04: .4byte 0x085B0A08
_0803EF08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803EF0E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803EF26
	asrs r0, r0, #0xc
	b _0803EF2C
_0803EF26:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803EF2C:
	strh r0, [r3, #4]
	mov r0, r8
	cmp r0, #0x13
	bgt _0803EF66
	ldr r1, _0803EF58 @ =0x00000824
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _0803EF66
	movs r1, #0xad
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803EF5C
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0
	bl FUN_0803c78c
	b _0803EF66
	.align 2, 0
_0803EF58: .4byte 0x00000824
_0803EF5C:
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0803c78c
_0803EF66:
	mov r0, r8
	cmp r0, #0x45
	ble _0803EF74
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803EF74:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803ef80
FUN_0803ef80: @ 0x0803EF80
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r6, #0
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r0, r0, r6
	mov r8, r0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803F070
	movs r4, #0
	strb r4, [r1]
	adds r3, r6, #0
	adds r3, #0xa0
	ldrb r0, [r3]
	cmp r0, #1
	bls _0803EFBC
	movs r0, #0x40
	adds r2, r6, #0
	adds r2, #0x4d
	strb r0, [r2]
	movs r1, #0xff
	movs r0, #2
	b _0803EFC6
_0803EFBC:
	adds r2, r6, #0
	adds r2, #0x4d
	strb r4, [r2]
	movs r1, #0xff
	movs r0, #1
_0803EFC6:
	strb r0, [r3]
	ldrb r0, [r2]
	adds r0, #0x10
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r2, r5, r1
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	mov r1, r8
	movs r3, #0x10
	bl FUN_08022c34
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	movs r4, #0xae
	lsls r4, r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	ldr r0, _0803F048 @ =0x000002B9
	adds r1, r5, r0
	movs r0, #5
	strb r0, [r1]
	ldr r2, _0803F04C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803F050 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0803F054 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _0803F05C
	movs r1, #1
	movs r2, #2
	ldr r3, _0803F058 @ =0x000002BD
	adds r0, r5, r3
_0803F038:
	strb r2, [r0]
	subs r2, #2
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0803F038
	b _0803F070
	.align 2, 0
_0803F048: .4byte 0x000002B9
_0803F04C: .4byte 0x030046B8
_0803F050: .4byte 0x000003FF
_0803F054: .4byte 0x0203B400
_0803F058: .4byte 0x000002BD
_0803F05C:
	movs r1, #1
	movs r2, #3
	ldr r4, _0803F0D0 @ =0x000002BD
	adds r0, r5, r4
_0803F064:
	strb r2, [r0]
	subs r2, #2
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0803F064
_0803F070:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F084
	b _0803F2E6
_0803F084:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F09A
	b _0803F2E6
_0803F09A:
	movs r2, #0xb1
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803F0B0
	adds r0, r2, #2
	strh r0, [r3]
_0803F0B0:
	ldr r2, _0803F0D4 @ =0x085B0A08
	lsls r0, r7, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803F0D8
	asrs r1, r0, #0xc
	b _0803F0DE
	.align 2, 0
_0803F0D0: .4byte 0x000002BD
_0803F0D4: .4byte 0x085B0A08
_0803F0D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803F0DE:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r7, #0xb0
	lsls r7, r7, #1
	adds r1, r5, r7
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0803F0F4
	movs r0, #0
	strh r0, [r1]
_0803F0F4:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r2, [r0]
	cmp r2, #0
	beq _0803F108
	cmp r2, #1
	bne _0803F106
	b _0803F2D4
_0803F106:
	b _0803F2E6
_0803F108:
	mov r3, r8
	ldrh r0, [r3, #0x14]
	cmp r0, #4
	bne _0803F112
	strh r2, [r3, #0xc]
_0803F112:
	movs r7, #0xae
	lsls r7, r7, #1
	adds r4, r5, r7
	ldrh r0, [r4]
	cmp r0, #0x12
	bne _0803F124
	ldr r0, _0803F17C @ =0x0000035E
	bl PlaySound_0824078c
_0803F124:
	ldrh r0, [r4]
	cmp r0, #0x1e
	beq _0803F130
	cmp r0, #0x32
	beq _0803F130
	b _0803F27E
_0803F130:
	ldr r1, _0803F180 @ =0x000002B9
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r3, #0xae
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r4, #0xaf
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r2, [r2]
	adds r0, r0, r2
	ldrb r2, [r0]
	add r0, sp, #0x18
	bl FUN_08234f90
	add r7, sp, #0x18
	adds r0, r7, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0803F176
	cmp r1, #0
	blt _0803F176
	ldr r0, _0803F184 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0803F176
	ldr r0, _0803F188 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0803F18C
_0803F176:
	movs r4, #0
	b _0803F19A
	.align 2, 0
_0803F17C: .4byte 0x0000035E
_0803F180: .4byte 0x000002B9
_0803F184: .4byte 0x030046A8
_0803F188: .4byte 0x030046AC
_0803F18C:
	ldr r0, _0803F1AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0803F19A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0803F1B0
	adds r0, #4
	b _0803F1BC
	.align 2, 0
_0803F1AC: .4byte 0x030046A4
_0803F1B0:
	ldr r0, _0803F1D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0803F1BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0803F1D4
	cmp r2, #2
	beq _0803F1D8
	b _0803F1DC
	.align 2, 0
_0803F1D0: .4byte 0x030046A4
_0803F1D4:
	ldrb r0, [r7, #4]
	b _0803F1DA
_0803F1D8:
	ldrb r0, [r7]
_0803F1DA:
	subs r1, r1, r0
_0803F1DC:
	add r3, sp, #0x18
	strh r1, [r3, #2]
	movs r7, #0x86
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r2, [r0]
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r1, r3, #0
	movs r4, #0
	ldrsh r1, [r1, r4]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r2, r7]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r4, r0, #0
	ldr r7, _0803F2BC @ =0x000002DE
	adds r0, r5, r7
	movs r1, #0
	ldrsh r3, [r0, r1]
	ldr r2, _0803F2C0 @ =0x000002B6
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803F222
	subs r7, #0x18
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	asrs r3, r0, #6
_0803F222:
	ldr r2, _0803F2C4 @ =0x00000958
	adds r0, r5, r2
	ldr r0, [r0]
	movs r7, #0xb9
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r7, #0
	ldrsh r2, [r1, r7]
	movs r7, #0xb8
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp]
	ldr r7, _0803F2C8 @ =0x000002E2
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #4]
	ldr r7, _0803F2CC @ =0x000002E6
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #8]
	movs r7, #0xba
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #0xc]
	ldr r7, _0803F2D0 @ =0x000002EA
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #0x10]
	add r1, sp, #0x18
	str r1, [sp, #0x14]
	adds r1, r4, #0
	bl FUN_0805eee4
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803F27E:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r4, r5, r3
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _0803F2E6
	movs r7, #0xcb
	lsls r7, r7, #2
	adds r2, r5, r7
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	adds r0, r6, #0
	mov r1, r8
	movs r3, #0x10
	bl FUN_08022c34
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r4]
	b _0803F2E6
	.align 2, 0
_0803F2BC: .4byte 0x000002DE
_0803F2C0: .4byte 0x000002B6
_0803F2C4: .4byte 0x00000958
_0803F2C8: .4byte 0x000002E2
_0803F2CC: .4byte 0x000002E6
_0803F2D0: .4byte 0x000002EA
_0803F2D4:
	mov r3, r8
	ldrb r1, [r3, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803F2E6
	adds r0, r6, #0
	adds r0, #0xa7
	strb r2, [r0]
_0803F2E6:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803f2f4
FUN_0803f2f4: @ 0x0803F2F4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	mov r8, r1
	adds r5, r6, #0
	movs r0, #0x48
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r7, r6, r1
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803F380
	movs r4, #0
	strb r4, [r1]
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r3, #0xe
	bl FUN_08022c9c
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
_0803F380:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F394
	b _0803F5AA
_0803F394:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F3AA
	b _0803F5AA
_0803F3AA:
	movs r4, #0xb1
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803F3C0
	adds r0, r2, #2
	strh r0, [r3]
_0803F3C0:
	ldr r2, _0803F3E0 @ =0x085B0A08
	mov r4, r8
	lsls r0, r4, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803F3E4
	asrs r1, r0, #0xc
	b _0803F3EA
	.align 2, 0
_0803F3E0: .4byte 0x085B0A08
_0803F3E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803F3EA:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r3, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0803F400
	strh r3, [r1]
_0803F400:
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r0, [r2]
	cmp r0, #1
	beq _0803F468
	cmp r0, #1
	bgt _0803F416
	cmp r0, #0
	beq _0803F422
	b _0803F5AA
_0803F416:
	cmp r0, #2
	beq _0803F492
	cmp r0, #3
	bne _0803F420
	b _0803F598
_0803F420:
	b _0803F5AA
_0803F422:
	ldrh r0, [r7, #0x14]
	cmp r0, #7
	bne _0803F434
	ldrh r0, [r7, #0xc]
	cmp r0, #1
	bne _0803F434
	ldr r0, _0803F464 @ =0x0000035E
	bl PlaySound_0824078c
_0803F434:
	movs r0, #8
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r7, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803F44A
	b _0803F5AA
_0803F44A:
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r4, #0xae
	lsls r4, r4, #1
	adds r1, r5, r4
	movs r0, #0
	strh r0, [r1]
	b _0803F5AA
	.align 2, 0
_0803F464: .4byte 0x0000035E
_0803F468:
	movs r0, #8
	movs r7, #0xb5
	lsls r7, r7, #1
	adds r1, r5, r7
	strb r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _0803F488
	b _0803F5AA
_0803F488:
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	strh r3, [r1]
	b _0803F5AA
_0803F492:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0803F4A6
	cmp r0, #0x10
	beq _0803F4A6
	cmp r0, #0x20
	bne _0803F53C
_0803F4A6:
	add r2, sp, #0x14
	mov r3, sb
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldrh r0, [r2, #2]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r0, r4
	strh r0, [r2, #2]
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	movs r7, #0xae
	lsls r7, r7, #1
	adds r1, r5, r7
	subs r0, #0x10
	ldrh r1, [r1]
	adds r4, r0, r1
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r3, [r0, r2]
	ldr r7, _0803F584 @ =0x000002B6
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803F4EE
	subs r1, #0x26
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	asrs r3, r0, #6
_0803F4EE:
	ldr r7, _0803F588 @ =0x00000958
	adds r0, r5, r7
	ldr r0, [r0]
	ldr r2, _0803F58C @ =0x000002F2
	adds r1, r5, r2
	movs r7, #0
	ldrsh r2, [r1, r7]
	ldr r7, _0803F590 @ =0x000002EE
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp]
	movs r7, #0xbc
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #4]
	movs r7, #0xbd
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #8]
	ldr r7, _0803F594 @ =0x000002F6
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #0xc]
	add r1, sp, #0x14
	str r1, [sp, #0x10]
	adds r1, r4, #0
	bl FUN_0805ef68
	movs r0, #4
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_0803F53C:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _0803F5AA
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r2]
	movs r7, #0xd3
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0x17
	bl FUN_08022c9c
	b _0803F5AA
	.align 2, 0
_0803F584: .4byte 0x000002B6
_0803F588: .4byte 0x00000958
_0803F58C: .4byte 0x000002F2
_0803F590: .4byte 0x000002EE
_0803F594: .4byte 0x000002F6
_0803F598:
	ldrb r1, [r7, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803F5AA
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803F5AA:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803f5b8
FUN_0803f5b8: @ 0x0803F5B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	adds r6, r1, #0
	mov r7, r8
	adds r0, #0x48
	str r0, [sp, #0x14]
	movs r1, #0xd3
	lsls r1, r1, #2
	add r1, r8
	str r1, [sp, #0x18]
	mov r1, r8
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803F646
	movs r5, #0
	strb r5, [r1]
	mov r0, r8
	adds r0, #0xc8
	ldrb r0, [r0]
	mov r3, r8
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	mov r0, r8
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, r8
	adds r0, #0xa1
	strb r1, [r0]
	movs r2, #0xcb
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, r8
	ldr r1, [sp, #0x18]
	movs r3, #0xe
	bl FUN_08022c9c
	movs r0, #0xaf
	lsls r0, r0, #1
	add r0, r8
	strh r5, [r0]
	movs r0, #0xae
	lsls r0, r0, #1
	add r0, r8
	strh r5, [r0]
_0803F646:
	mov r0, r8
	adds r0, #0xfc
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F65A
	b _0803F8BA
_0803F65A:
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, r8
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F670
	b _0803F8BA
_0803F670:
	movs r0, #0xb1
	lsls r0, r0, #1
	add r0, r8
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803F686
	adds r0, r2, #2
	strh r0, [r3]
_0803F686:
	ldr r2, _0803F6A4 @ =0x085B0A08
	lsls r0, r6, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803F6A8
	asrs r1, r0, #0xc
	b _0803F6AE
	.align 2, 0
_0803F6A4: .4byte 0x085B0A08
_0803F6A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803F6AE:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r5, #0xb0
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r4, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0803F6C4
	strh r4, [r1]
_0803F6C4:
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r2, r7, r0
	ldrh r3, [r2]
	cmp r3, #1
	bne _0803F6D2
	b _0803F86C
_0803F6D2:
	cmp r3, #1
	bgt _0803F6DC
	cmp r3, #0
	beq _0803F6E4
	b _0803F8BA
_0803F6DC:
	cmp r3, #2
	bne _0803F6E2
	b _0803F8A8
_0803F6E2:
	b _0803F8BA
_0803F6E4:
	ldr r1, [sp, #0x18]
	ldrh r0, [r1, #0x14]
	cmp r0, #7
	bne _0803F6F8
	ldrh r0, [r1, #0xc]
	cmp r0, #1
	bne _0803F6F8
	ldr r0, _0803F848 @ =0x0000035E
	bl PlaySound_0824078c
_0803F6F8:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	beq _0803F70E
	b _0803F822
_0803F70E:
	add r2, sp, #0xc
	ldr r3, [sp, #0x14]
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldrh r0, [r2, #2]
	adds r0, #0xf0
	strh r0, [r2, #2]
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	ldrsh r4, [r0, r5]
	ldr r1, _0803F84C @ =0x000002B6
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803F740
	ldr r2, _0803F850 @ =0x000002C6
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	asrs r4, r0, #6
_0803F740:
	ldr r5, _0803F854 @ =0x030046B8
	mov sl, r5
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _0803F858 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _0803F85C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r3, [sp, #0x14]
	ldrb r2, [r3, #5]
	movs r5, #3
	ands r0, r5
	adds r0, #0xa
	subs r2, r2, r0
	ldr r0, _0803F860 @ =0x00000954
	adds r0, r0, r7
	mov sb, r0
	ldr r0, [r0]
	ldr r1, _0803F864 @ =0x000002FE
	adds r1, r1, r7
	mov r8, r1
	movs r5, #0
	ldrsh r3, [r1, r5]
	adds r3, #2
	mov ip, r3
	str r4, [sp]
	ldr r1, _0803F868 @ =0x000002FA
	adds r6, r7, r1
	movs r3, #0
	ldrsh r1, [r6, r3]
	str r1, [sp, #4]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r5, r7, r1
	movs r3, #0
	ldrsh r1, [r5, r3]
	str r1, [sp, #8]
	add r1, sp, #0xc
	mov r3, ip
	bl FUN_0805e6bc
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0803F858 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _0803F85C @ =0x0203B400
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r0, #3
	ands r2, r0
	ldr r1, [sp, #0x14]
	ldrb r1, [r1, #5]
	adds r2, r2, r1
	mov r3, sb
	ldr r0, [r3]
	mov r1, r8
	movs r3, #0
	ldrsh r1, [r1, r3]
	mov ip, r1
	str r4, [sp]
	movs r3, #0
	ldrsh r1, [r6, r3]
	str r1, [sp, #4]
	movs r3, #0
	ldrsh r1, [r5, r3]
	str r1, [sp, #8]
	add r1, sp, #0xc
	mov r3, ip
	bl FUN_0805e6bc
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0803F858 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _0803F85C @ =0x0203B400
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r0, #3
	ands r2, r0
	adds r2, #0xa
	ldr r1, [sp, #0x14]
	ldrb r1, [r1, #5]
	adds r2, r2, r1
	mov r3, sb
	ldr r0, [r3]
	mov r1, r8
	movs r3, #0
	ldrsh r1, [r1, r3]
	mov r8, r1
	mov r3, r8
	adds r3, #2
	str r4, [sp]
	movs r4, #0
	ldrsh r1, [r6, r4]
	str r1, [sp, #4]
	movs r4, #0
	ldrsh r1, [r5, r4]
	str r1, [sp, #8]
	add r1, sp, #0xc
	bl FUN_0805e6bc
	movs r0, #0xea
	bl PlaySound_0824078c
_0803F822:
	ldr r5, [sp, #0x18]
	ldrb r1, [r5, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803F8BA
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r2, r7, r0
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0803F8BA
	.align 2, 0
_0803F848: .4byte 0x0000035E
_0803F84C: .4byte 0x000002B6
_0803F850: .4byte 0x000002C6
_0803F854: .4byte 0x030046B8
_0803F858: .4byte 0x000003FF
_0803F85C: .4byte 0x0203B400
_0803F860: .4byte 0x00000954
_0803F864: .4byte 0x000002FE
_0803F868: .4byte 0x000002FA
_0803F86C:
	movs r5, #0xae
	lsls r5, r5, #1
	adds r1, r7, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _0803F8BA
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	strh r4, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r4, #0xcb
	lsls r4, r4, #2
	adds r2, r7, r4
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, r8
	movs r3, #0x17
	bl FUN_08022c9c
	b _0803F8BA
_0803F8A8:
	ldr r5, [sp, #0x18]
	ldrb r0, [r5, #0x1d]
	ands r3, r0
	cmp r3, #0
	beq _0803F8BA
	mov r1, r8
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803F8BA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803f8cc
FUN_0803f8cc: @ 0x0803F8CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	mov sl, r1
	adds r6, r7, #0
	adds r0, #0x48
	str r0, [sp, #0x14]
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r1, r1, r7
	mov sb, r1
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803F9CA
	movs r4, #0
	strb r4, [r1]
	adds r0, r7, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r3, r7, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r0, #2
	mov r8, r0
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	mov r1, sb
	movs r3, #0xe
	bl FUN_08022c9c
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r5, #0
	strh r4, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r0, #0
	movs r1, #0
	bl FUN_08050e2c
	movs r2, #0xb
	ldr r4, _0803F990 @ =0x00000818
	adds r1, r7, r4
	mov r0, r8
	strb r0, [r1]
	ldr r3, _0803F994 @ =0x0000081A
	adds r0, r7, r3
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _0803F998
	adds r4, #1
	adds r1, r7, r4
	movs r0, #0x1f
	strb r0, [r1]
	b _0803F9C2
	.align 2, 0
_0803F990: .4byte 0x00000818
_0803F994: .4byte 0x0000081A
_0803F998:
	cmp r0, #0
	bne _0803F9A8
	ldr r1, _0803F9A4 @ =0x00000819
	adds r0, r7, r1
	b _0803F9C0
	.align 2, 0
_0803F9A4: .4byte 0x00000819
_0803F9A8:
	cmp r0, #2
	bne _0803F9B8
	ldr r2, _0803F9B4 @ =0x00000819
	adds r0, r7, r2
	b _0803F9C0
	.align 2, 0
_0803F9B4: .4byte 0x00000819
_0803F9B8:
	cmp r0, #3
	bne _0803F9C2
	ldr r3, _0803FA24 @ =0x00000819
	adds r0, r7, r3
_0803F9C0:
	strb r5, [r0]
_0803F9C2:
	ldr r4, _0803FA28 @ =0x0000081E
	adds r1, r6, r4
	movs r0, #0
	strb r0, [r1]
_0803F9CA:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0803FA4C
	movs r7, #0xad
	lsls r7, r7, #2
	adds r0, r6, r7
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0803FA28 @ =0x0000081E
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _0803FA24 @ =0x00000819
	adds r0, r6, r3
	strb r1, [r0]
	ldr r4, _0803FA2C @ =0x00000818
	adds r1, r6, r4
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_0803c1bc
	ldr r7, _0803FA30 @ =0x0000081A
	adds r1, r6, r7
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	cmp r1, #0
	bne _0803FA34
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r2, #0x83
	lsls r2, r2, #3
	adds r0, r6, r2
	str r0, [r1]
	b _0803FC5E
	.align 2, 0
_0803FA24: .4byte 0x00000819
_0803FA28: .4byte 0x0000081E
_0803FA2C: .4byte 0x00000818
_0803FA30: .4byte 0x0000081A
_0803FA34:
	ldr r0, _0803FA48 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r1, r6, r3
	str r0, [r1]
	b _0803FC5E
	.align 2, 0
_0803FA48: .4byte 0x03003584
_0803FA4C:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803FACC
	movs r2, #0xad
	lsls r2, r2, #2
	adds r0, r6, r2
	strb r4, [r0]
	ldr r3, _0803FAA4 @ =0x0000081E
	adds r0, r6, r3
	strb r4, [r0]
	ldr r7, _0803FAA8 @ =0x00000819
	adds r0, r6, r7
	strb r4, [r0]
	ldr r0, _0803FAAC @ =0x00000818
	adds r1, r6, r0
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_0803c1bc
	ldr r2, _0803FAB0 @ =0x0000081A
	adds r1, r6, r2
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	cmp r1, #0
	bne _0803FAB4
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0x83
	lsls r4, r4, #3
	adds r0, r6, r4
	str r0, [r1]
	b _0803FC5E
	.align 2, 0
_0803FAA4: .4byte 0x0000081E
_0803FAA8: .4byte 0x00000819
_0803FAAC: .4byte 0x00000818
_0803FAB0: .4byte 0x0000081A
_0803FAB4:
	ldr r0, _0803FAC8 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r7, #0xe5
	lsls r7, r7, #2
	adds r1, r6, r7
	str r0, [r1]
	b _0803FC5E
	.align 2, 0
_0803FAC8: .4byte 0x03003584
_0803FACC:
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803FAE2
	adds r0, r2, #2
	strh r0, [r3]
_0803FAE2:
	ldr r2, _0803FB04 @ =0x085B0A08
	mov r4, sl
	lsls r0, r4, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803FB08
	asrs r1, r0, #0xc
	b _0803FB0E
	.align 2, 0
_0803FB04: .4byte 0x085B0A08
_0803FB08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803FB0E:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r4, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0803FB24
	strh r4, [r1]
_0803FB24:
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r3, [r2]
	cmp r3, #1
	beq _0803FC10
	cmp r3, #1
	bgt _0803FB3A
	cmp r3, #0
	beq _0803FB42
	b _0803FC5E
_0803FB3A:
	cmp r3, #2
	bne _0803FB40
	b _0803FC4C
_0803FB40:
	b _0803FC5E
_0803FB42:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x14
	bne _0803FBD6
	add r2, sp, #0xc
	ldr r3, [sp, #0x14]
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldrh r0, [r2, #2]
	adds r0, #0xf0
	strh r0, [r2, #2]
	movs r4, #0xc0
	lsls r4, r4, #2
	adds r0, r6, r4
	movs r7, #0
	ldrsh r2, [r0, r7]
	ldr r0, _0803FBFC @ =0x000002C1
	adds r5, r6, r0
	ldrb r1, [r5]
	ldr r3, _0803FC00 @ =0x00000302
	adds r0, r6, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r1, r0
	adds r4, r2, r0
	ldr r7, _0803FC04 @ =0x000002B6
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803FB9A
	ldr r1, _0803FC08 @ =0x000002C6
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	asrs r4, r0, #6
_0803FB9A:
	ldr r3, _0803FC0C @ =0x00000954
	adds r0, r6, r3
	ldr r0, [r0]
	ldr r7, [sp, #0x14]
	ldrb r2, [r7, #5]
	movs r3, #0xc2
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r7, #0
	ldrsh r3, [r1, r7]
	str r4, [sp]
	movs r4, #0xc1
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #4]
	adds r4, #2
	adds r1, r6, r4
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #8]
	add r1, sp, #0xc
	bl FUN_0805e79c
	movs r0, #0xea
	bl PlaySound_0824078c
	movs r0, #0
	strb r0, [r5]
_0803FBD6:
	mov r0, sb
	ldrb r1, [r0, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803FC5E
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	b _0803FC5E
	.align 2, 0
_0803FBFC: .4byte 0x000002C1
_0803FC00: .4byte 0x00000302
_0803FC04: .4byte 0x000002B6
_0803FC08: .4byte 0x000002C6
_0803FC0C: .4byte 0x00000954
_0803FC10:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc7
	bls _0803FC5E
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	strh r4, [r1]
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r4, #0xcb
	lsls r4, r4, #2
	adds r2, r6, r4
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x17
	bl FUN_08022c9c
	b _0803FC5E
_0803FC4C:
	mov r1, sb
	ldrb r0, [r1, #0x1d]
	ands r3, r0
	cmp r3, #0
	beq _0803FC5E
	adds r1, r7, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803FC5E:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803fc70
FUN_0803fc70: @ 0x0803FC70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov sb, r1
	adds r6, r5, #0
	movs r0, #0x48
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r1, r1, r5
	mov r8, r1
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803FD3E
	movs r2, #0
	mov ip, r2
	mov r3, ip
	strb r3, [r1]
	adds r0, r5, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r2, r5, #0
	adds r2, #0x4d
	strb r0, [r2]
	ldrb r0, [r2]
	adds r0, #0x20
	movs r7, #0xff
	ands r0, r7
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r3, r5, #0
	adds r3, #0xa0
	strb r1, [r3]
	ldrb r0, [r2]
	adds r0, #0x10
	ands r0, r7
	asrs r0, r0, #5
	adds r0, #3
	movs r4, #7
	ands r0, r4
	adds r1, r5, #0
	adds r1, #0xa1
	strb r0, [r1]
	ldrb r0, [r3]
	cmp r0, #1
	bls _0803FCE6
	movs r0, #0x40
	strb r0, [r2]
	movs r0, #2
	b _0803FCEC
_0803FCE6:
	mov r0, ip
	strb r0, [r2]
	movs r0, #1
_0803FCEC:
	strb r0, [r3]
	ldrb r0, [r2]
	adds r0, #0x10
	ands r0, r7
	asrs r0, r0, #5
	adds r0, #3
	ands r0, r4
	strb r0, [r1]
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	adds r2, r4, #0
	movs r3, #0x10
	bl FUN_08022c34
	adds r0, r5, #0
	adds r0, #0xb0
	ldrh r2, [r0]
	mov r0, r8
	adds r1, r4, #0
	movs r3, #6
	bl FUN_082371ac
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	ldr r0, _0803FDB4 @ =0x0000035F
	bl PlaySound_0824078c
_0803FD3E:
	movs r1, #4
	adds r4, r5, #0
	adds r4, #0x98
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r1, #0xb7
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0xba
	lsls r3, r3, #1
	adds r0, r6, r3
	str r1, [r0]
	adds r2, #0x12
	adds r0, r6, r2
	str r1, [r0]
	subs r3, #0x74
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803FD7E
	b _0803FEE0
_0803FD7E:
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803FD94
	adds r0, r2, #2
	strh r0, [r3]
_0803FD94:
	ldr r2, _0803FDB8 @ =0x085B0A08
	mov r1, sb
	lsls r0, r1, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803FDBC
	asrs r1, r0, #0xc
	b _0803FDC2
	.align 2, 0
_0803FDB4: .4byte 0x0000035F
_0803FDB8: .4byte 0x085B0A08
_0803FDBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803FDC2:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r2, #0
	mov sb, r2
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0803FDDC
	mov r3, sb
	strh r3, [r1]
_0803FDDC:
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r7, r6, r0
	ldrh r0, [r7]
	cmp r0, #1
	beq _0803FE2C
	cmp r0, #1
	bgt _0803FDF2
	cmp r0, #0
	beq _0803FDF8
	b _0803FEE0
_0803FDF2:
	cmp r0, #2
	beq _0803FEC0
	b _0803FEE0
_0803FDF8:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	mov r3, r8
	ldrh r0, [r3, #0x14]
	cmp r0, #2
	bls _0803FE14
	movs r1, #8
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0803FE14:
	mov r0, r8
	ldrb r1, [r0, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803FEE0
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	mov r1, sb
	strh r1, [r2]
	b _0803FEE0
_0803FE2C:
	movs r1, #0x18
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r4, r6, r2
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bne _0803FE58
	movs r3, #0xa7
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, sl
	str r0, [r2, #8]
	str r1, [r2, #0xc]
_0803FE58:
	ldrh r0, [r4]
	cmp r0, #0x1d
	bls _0803FEE0
	adds r0, r5, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #6
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	movs r3, #0x10
	bl FUN_08022c34
	mov r0, r8
	movs r1, #0x40
	bl FUN_0823723c
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	mov r0, sb
	strh r0, [r4]
	b _0803FEE0
_0803FEC0:
	mov r1, r8
	ldrh r0, [r1, #0x14]
	cmp r0, #2
	bhi _0803FED0
	movs r1, #8
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0803FED0:
	mov r2, r8
	ldrh r0, [r2, #0x14]
	cmp r0, #6
	bne _0803FEE0
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803FEE0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803fef0
FUN_0803fef0: @ 0x0803FEF0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r5, #0
	movs r0, #0x48
	adds r0, r0, r5
	mov sb, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r1, r1, r5
	mov r8, r1
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803FF48
	movs r4, #0
	strb r4, [r1]
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	mov r1, r8
	movs r3, #5
	bl FUN_08022c9c
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
_0803FF48:
	movs r1, #0xb7
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #0xe
	adds r0, r5, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r5, r2
	str r1, [r0]
	movs r2, #0xd
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r6, #9
	bgt _0803FFCA
	movs r0, #0xa
	subs r0, r0, r6
	adds r3, r5, #0
	adds r3, #0x58
	mov r1, sb
	ldrb r4, [r1, #5]
	lsls r6, r0, #1
	ldr r2, _0803FFA0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803FFA4
	asrs r1, r0, #0xc
	b _0803FFAA
	.align 2, 0
_0803FFA0: .4byte 0x085B0A08
_0803FFA4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803FFAA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803FFC2
	asrs r0, r0, #0xc
	b _0803FFC8
_0803FFC2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803FFC8:
	strh r0, [r3, #4]
_0803FFCA:
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r6, r7, r0
	ldrh r4, [r6]
	cmp r4, #1
	beq _08040028
	cmp r4, #1
	bgt _0803FFE0
	cmp r4, #0
	beq _0803FFE6
	b _08040090
_0803FFE0:
	cmp r4, #2
	beq _0804005E
	b _08040090
_0803FFE6:
	movs r0, #8
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	mov r0, r8
	ldrb r1, [r0, #0x1d]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08040090
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r2, r7, r1
	str r3, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	mov r1, r8
	movs r3, #7
	bl FUN_08022c9c
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	b _08040090
_08040028:
	mov r0, r8
	ldrb r1, [r0, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08040090
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r2, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	mov r1, r8
	movs r3, #0
	bl FUN_08022d24
	ldrh r0, [r6]
	adds r0, #1
	movs r1, #0
	strh r0, [r6]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08040090
_0804005E:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _08040090
	ldr r1, _080400A0 @ =FUN_0803fc70
	movs r0, #0xc
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x8c
	movs r0, #0
	str r0, [r1]
	adds r1, #0x1d
	movs r0, #1
	strb r0, [r1]
_08040090:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080400A0: .4byte FUN_0803fc70

	thumb_func_start FUN_080400a4
FUN_080400a4: @ 0x080400A4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08040102
	movs r4, #0
	strb r4, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #5
	bl FUN_08022c9c
	movs r0, #0xdb
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r5, #0
	bl FUN_08022fb8
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	movs r0, #0
	movs r1, #1
	bl FUN_08050e50
	bl FUN_08050d28
_08040102:
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08040116
	subs r0, r2, #4
	b _08040118
_08040116:
	movs r0, #0
_08040118:
	strh r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _0804012E
	subs r0, r2, #4
	b _08040130
_0804012E:
	movs r0, #0
_08040130:
	strh r0, [r1]
	movs r1, #0xb7
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0xba
	lsls r3, r3, #1
	adds r0, r6, r3
	str r1, [r0]
	adds r2, #0x12
	adds r0, r6, r2
	str r1, [r0]
	movs r2, #0xd
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	subs r3, #0x18
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x80
	bne _0804017C
	movs r0, #0xdb
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r5, #0
	bl FUN_08023024
_0804017C:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08040184
FUN_08040184: @ 0x08040184
	push {lr}
	adds r2, r0, #0
	movs r1, #4
	ldr r0, _080401A4 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080401A0
	adds r1, r2, #0
	adds r1, #0xa7
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_08022f78
_080401A0:
	pop {r0}
	bx r0
	.align 2, 0
_080401A4: .4byte 0x03002BC0

	thumb_func_start FUN_080401a8
FUN_080401a8: @ 0x080401A8
	push {lr}
	mov ip, r0
	mov r2, ip
	adds r2, #0xa2
	ldrb r0, [r2]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bhi _080401E4
	ldr r1, _080401E0 @ =0x085AAFB8
	ldrb r2, [r2]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	mov r0, ip
	adds r0, #0xa3
	movs r3, #0
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	mov r1, ip
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	b _080401E6
	.align 2, 0
_080401E0: .4byte 0x085AAFB8
_080401E4:
	movs r0, #0
_080401E6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080401ec
FUN_080401ec: @ 0x080401EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r4, r0, #0
	adds r5, r4, #0
	adds r0, #0x48
	str r0, [sp, #0x14]
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r1, r4, r1
	str r1, [sp, #0x18]
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r2, r2, r4
	mov ip, r2
	movs r0, #0
	ldrsh r7, [r2, r0]
	mov r8, r7
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r3, r4, r1
	ldrh r2, [r3]
	str r2, [sp, #0x10]
	movs r7, #0xba
	lsls r7, r7, #1
	adds r2, r4, r7
	ldr r6, [r2]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r7, [r1]
	mov sl, r7
	movs r0, #0
	mov r7, ip
	strh r0, [r7]
	strh r0, [r3]
	str r0, [r2]
	str r0, [r1]
	bl FUN_08050e80
	cmp r0, #0
	bne _0804024A
	movs r0, #0
	mov r8, r0
_0804024A:
	mov r1, r8
	cmp r1, #0
	bgt _08040252
	b _080404CC
_08040252:
	adds r0, r4, #0
	adds r0, #0x90
	ldrh r1, [r0]
	mov r2, r8
	subs r1, r1, r2
	strh r1, [r0]
	movs r7, #0xa9
	lsls r7, r7, #2
	adds r2, r4, r7
	ldr r0, [r4, #0x50]
	ldr r1, [r4, #0x54]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _08040282
	movs r0, #7
	ands r0, r6
	cmp r0, #0
	beq _08040282
	adds r0, r2, #0
	movs r1, #0
	bl FUN_08050cb8
_08040282:
	movs r0, #0x7f
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _080402CC
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	beq _080402A2
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #1
	bl FUN_08050cb8
	b _080402CC
_080402A2:
	movs r0, #2
	ands r0, r6
	cmp r0, #0
	beq _080402B8
	movs r7, #0xa9
	lsls r7, r7, #2
	adds r0, r4, r7
	movs r1, #2
	bl FUN_08050cb8
	b _080402CC
_080402B8:
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	beq _080402CC
	movs r1, #0xa9
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #3
	bl FUN_08050cb8
_080402CC:
	movs r2, #1
	mov sb, r2
	mov r7, sl
	ands r7, r2
	cmp r7, #0
	beq _080402E2
	movs r1, #0xa9
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0803ca40
_080402E2:
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r7, #0
	mov sl, r7
	movs r0, #0x14
	strh r0, [r1]
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0xa
	strh r0, [r1]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r7, r4, r1
	movs r2, #0x83
	lsls r2, r2, #3
	adds r2, r4, r2
	str r2, [sp, #0x1c]
	str r2, [r7]
	ldr r3, _080403BC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _080403C0 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r3, [sp, #0x14]
	adds r3, #8
	add r0, sp, #8
	str r0, [sp]
	mov r1, sb
	str r1, [sp, #4]
	ldr r0, [sp, #0x18]
	mov r1, r8
	movs r2, #0
	bl FUN_0805fe7c
	adds r1, r5, #0
	adds r1, #0x90
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bgt _080403FC
	movs r0, #0
	strh r0, [r1]
	movs r2, #2
	adds r1, #8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080403C4 @ =FUN_080400a4
	movs r0, #0xe
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	movs r1, #0
	str r1, [r0]
	adds r0, #0x1d
	mov r2, sb
	strb r2, [r0]
	ldr r0, _080403C8 @ =0x000003CD
	bl PlaySound_0824078c
	ldr r1, _080403CC @ =0x000002B5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08040380
	b _080404B4
_08040380:
	movs r2, #0xad
	lsls r2, r2, #2
	adds r0, r4, r2
	mov r1, sl
	strb r1, [r0]
	ldr r2, _080403D0 @ =0x0000081E
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _080403D4 @ =0x00000819
	adds r0, r4, r1
	mov r2, sl
	strb r2, [r0]
	ldr r0, _080403D8 @ =0x00000818
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0803c1bc
	ldr r2, _080403DC @ =0x0000081A
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	cmp r1, #0
	bne _080403E0
	ldr r0, [sp, #0x1c]
	b _080403E8
	.align 2, 0
_080403BC: .4byte 0xFFFF0000
_080403C0: .4byte 0x0000FFFF
_080403C4: .4byte FUN_080400a4
_080403C8: .4byte 0x000003CD
_080403CC: .4byte 0x000002B5
_080403D0: .4byte 0x0000081E
_080403D4: .4byte 0x00000819
_080403D8: .4byte 0x00000818
_080403DC: .4byte 0x0000081A
_080403E0:
	ldr r0, _080403F4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
_080403E8:
	str r0, [r7]
	ldr r2, _080403F8 @ =0x000002B5
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	b _080404B4
	.align 2, 0
_080403F4: .4byte 0x03003584
_080403F8: .4byte 0x000002B5
_080403FC:
	movs r0, #8
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _080404C4
	movs r0, #7
	ands r6, r0
	cmp r6, #0
	beq _080404C4
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	mov r2, sb
	orrs r0, r2
	str r0, [r1]
	ldr r1, _08040484 @ =FUN_0803fef0
	movs r0, #0xd
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	movs r1, #0
	str r1, [r0]
	adds r0, #0x1d
	mov r2, sb
	strb r2, [r0]
	ldr r1, _08040488 @ =0x000002B5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080404AE
	movs r2, #0xad
	lsls r2, r2, #2
	adds r0, r4, r2
	mov r1, sl
	strb r1, [r0]
	ldr r2, _0804048C @ =0x0000081E
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _08040490 @ =0x00000819
	adds r0, r4, r1
	mov r2, sl
	strb r2, [r0]
	ldr r0, _08040494 @ =0x00000818
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0803c1bc
	ldr r2, _08040498 @ =0x0000081A
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	cmp r1, #0
	bne _0804049C
	ldr r0, [sp, #0x1c]
	b _080404A4
	.align 2, 0
_08040484: .4byte FUN_0803fef0
_08040488: .4byte 0x000002B5
_0804048C: .4byte 0x0000081E
_08040490: .4byte 0x00000819
_08040494: .4byte 0x00000818
_08040498: .4byte 0x0000081A
_0804049C:
	ldr r0, _080404B8 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
_080404A4:
	str r0, [r7]
	ldr r2, _080404BC @ =0x000002B5
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_080404AE:
	ldr r0, _080404C0 @ =0x00000362
	bl PlaySound_0824078c
_080404B4:
	movs r0, #1
	b _080404CE
	.align 2, 0
_080404B8: .4byte 0x03003584
_080404BC: .4byte 0x000002B5
_080404C0: .4byte 0x00000362
_080404C4:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_0824078c
_080404CC:
	movs r0, #0
_080404CE:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start BossShadeMan_Update
BossShadeMan_Update: @ 0x080404E0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0803cee4
	adds r0, r4, #0
	bl FUN_0803e68c
	adds r0, r4, #0
	bl FUN_08040184
	adds r0, r4, #0
	bl FUN_0803d0a4
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start BossShadeMan_Destroy
BossShadeMan_Destroy: @ 0x08040504
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013c70
	adds r0, r4, #0
	bl FUN_0803c264
	adds r0, r4, #0
	bl FUN_0803c76c
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	adds r0, r4, #0
	bl FUN_08022b04
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start BossShadeMan_Init
BossShadeMan_Init: @ 0x08040538
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	str r1, [sp, #0x24]
	mov sb, r7
	movs r0, #0x74
	movs r1, #7
	bl VM_GetKeywordValue
	mov r8, r0
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08022a0c
	ldr r0, _0804057C @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _08040580
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r7, r1
	str r2, [r0]
	movs r3, #0x86
	lsls r3, r3, #1
	adds r1, r7, r3
	adds r0, r2, #0
	adds r0, #0x2c
	str r0, [r1]
	b _08040590
	.align 2, 0
_0804057C: .4byte 0x03002BE0
_08040580:
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r7, r4
	str r2, [r0]
	movs r5, #0x86
	lsls r5, r5, #1
	adds r0, r7, r5
	str r2, [r0]
_08040590:
	ldr r0, _08040600 @ =0x0000CB05
	ldr r1, _08040604 @ =0x00005D36
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _080405A0
	b _08040D30
_080405A0:
	movs r6, #0xcb
	lsls r6, r6, #2
	adds r0, r7, r6
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040610
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08040608 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0804060C @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x20]
	bl Script_GetValue
	adds r6, r0, #0
	b _08040638
	.align 2, 0
_08040600: .4byte 0x0000CB05
_08040604: .4byte 0x00005D36
_08040608: .4byte 0xFFFF0000
_0804060C: .4byte 0x0000FFFF
_08040610:
	ldr r0, _08040674 @ =0x030046A0
	ldr r3, [r0]
	ldrh r0, [r3, #0x30]
	ldr r4, _08040678 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r2, [r3, #0x32]
	lsls r2, r2, #0x10
	ldr r0, _0804067C @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x1c]
	ldrh r1, [r3, #0x34]
	ldr r0, [sp, #0x20]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r6, #0x40
_08040638:
	ldr r0, [sp, #0x1c]
	asrs r0, r0, #0x10
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040684
	bl Script_GetValue
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _08040680 @ =0x0000028E
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	movs r5, #0xa4
	lsls r5, r5, #2
	adds r1, r7, r5
	strh r0, [r1]
	b _080406A4
	.align 2, 0
_08040674: .4byte 0x030046A0
_08040678: .4byte 0xFFFF0000
_0804067C: .4byte 0x0000FFFF
_08040680: .4byte 0x0000028E
_08040684:
	ldr r0, _080406C8 @ =0x030046A0
	ldr r1, [r0]
	ldrh r2, [r1, #0x30]
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r7, r3
	strh r2, [r0]
	ldrh r2, [r1, #0x32]
	ldr r4, _080406CC @ =0x0000028E
	adds r0, r7, r4
	strh r2, [r0]
	ldrh r1, [r1, #0x34]
	movs r5, #0xa4
	lsls r5, r5, #2
	adds r0, r7, r5
	strh r1, [r0]
_080406A4:
	adds r0, r7, #0
	bl FUN_0803c590
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080406D0
	bl Script_GetValue
	str r0, [sp, #0x28]
	bl Script_GetValue
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r1, r7, r2
	b _080406DE
	.align 2, 0
_080406C8: .4byte 0x030046A0
_080406CC: .4byte 0x0000028E
_080406D0:
	movs r3, #0xfa
	lsls r3, r3, #2
	str r3, [sp, #0x28]
	movs r4, #0xb1
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r0, #0x64
_080406DE:
	strh r0, [r1]
	ldr r5, _0804077C @ =0x0000030E
	adds r0, r7, r5
	movs r1, #0x40
	strb r1, [r0]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #0x4d
	movs r1, #0x80
	bl VM_GetKeywordValue
	ldr r3, _08040780 @ =0x000002C6
	adds r1, r7, r3
	strh r0, [r1]
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040790
	bl Script_GetValue
	movs r4, #0xb2
	lsls r4, r4, #2
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	subs r5, #0x44
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _08040784 @ =0x000002CE
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #8
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #8
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _08040788 @ =0x000002D6
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #0xc
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #6
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _0804078C @ =0x000002DA
	adds r1, r7, r2
	b _080407E8
	.align 2, 0
_0804077C: .4byte 0x0000030E
_08040780: .4byte 0x000002C6
_08040784: .4byte 0x000002CE
_08040788: .4byte 0x000002D6
_0804078C: .4byte 0x000002DA
_08040790:
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r2, #0x32
	strh r2, [r0]
	ldr r4, _08040880 @ =0x000002CA
	adds r0, r7, r4
	strh r2, [r0]
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r0, #0xf
	strh r0, [r1]
	ldr r0, _08040884 @ =0x000002CE
	adds r1, r7, r0
	movs r0, #0x5a
	strh r0, [r1]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r2, [r0]
	ldr r2, _08040888 @ =0x000002D2
	adds r0, r7, r2
	movs r2, #0x3c
	strh r2, [r0]
	adds r3, #0xc
	adds r1, r7, r3
	movs r0, #0x64
	strh r0, [r1]
	adds r4, #0xc
	adds r1, r7, r4
	movs r0, #0x50
	strh r0, [r1]
	adds r5, #0x10
	adds r0, r7, r5
	strh r2, [r0]
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #4
	strh r0, [r1]
	ldr r2, _0804088C @ =0x000002DA
	adds r1, r7, r2
	movs r0, #0x2d
_080407E8:
	strh r0, [r1]
	movs r0, #0x53
	bl VM_SeekToKeyword
	adds r3, r0, #0
	cmp r3, #0
	beq _080408A4
	bl Script_GetValue
	ldr r3, _08040890 @ =0x000002DE
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	movs r4, #0xb8
	lsls r4, r4, #2
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	ldr r5, _08040894 @ =0x000002E2
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _08040898 @ =0x000002E6
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #8
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #8
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _0804089C @ =0x000002EE
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #8
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #8
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _080408A0 @ =0x000002F6
	adds r1, r7, r3
	b _08040906
	.align 2, 0
_08040880: .4byte 0x000002CA
_08040884: .4byte 0x000002CE
_08040888: .4byte 0x000002D2
_0804088C: .4byte 0x000002DA
_08040890: .4byte 0x000002DE
_08040894: .4byte 0x000002E2
_08040898: .4byte 0x000002E6
_0804089C: .4byte 0x000002EE
_080408A0: .4byte 0x000002F6
_080408A4:
	ldr r4, _08040974 @ =0x000002DE
	adds r1, r7, r4
	movs r0, #0x50
	strh r0, [r1]
	movs r5, #0xb8
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r2, #0x3c
	strh r2, [r0]
	ldr r1, _08040978 @ =0x000002E2
	adds r0, r7, r1
	strh r2, [r0]
	adds r4, #6
	adds r1, r7, r4
	movs r0, #0x14
	strh r0, [r1]
	adds r5, #6
	adds r1, r7, r5
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #1
	strh r1, [r0]
	adds r4, #6
	adds r0, r7, r4
	strh r1, [r0]
	adds r5, #6
	adds r1, r7, r5
	movs r0, #0x5a
	strh r0, [r1]
	ldr r1, _0804097C @ =0x000002EE
	adds r0, r7, r1
	strh r2, [r0]
	adds r4, #6
	adds r0, r7, r4
	strh r2, [r0]
	adds r5, #6
	adds r1, r7, r5
	movs r0, #0x19
	strh r0, [r1]
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r3, [r0]
	ldr r2, _08040980 @ =0x000002F6
	adds r1, r7, r2
	movs r0, #4
_08040906:
	strh r0, [r1]
	movs r0, #0x42
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040990
	bl Script_GetValue
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _08040984 @ =0x000002FA
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	movs r5, #0xbf
	lsls r5, r5, #2
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08040988 @ =0x000002FE
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #0xa
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #0xa
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xc2
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _0804098C @ =0x00000302
	adds r1, r7, r3
	b _080409D8
	.align 2, 0
_08040974: .4byte 0x000002DE
_08040978: .4byte 0x000002E2
_0804097C: .4byte 0x000002EE
_08040980: .4byte 0x000002F6
_08040984: .4byte 0x000002FA
_08040988: .4byte 0x000002FE
_0804098C: .4byte 0x00000302
_08040990:
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r0, #0x46
	strh r0, [r1]
	ldr r5, _080409FC @ =0x000002FA
	adds r0, r7, r5
	movs r3, #0x1e
	strh r3, [r0]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r2, #8
	strh r2, [r0]
	adds r4, #6
	adds r1, r7, r4
	movs r0, #0x18
	strh r0, [r1]
	adds r5, #6
	adds r1, r7, r5
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r3, [r0]
	ldr r3, _08040A00 @ =0x00000306
	adds r0, r7, r3
	strh r2, [r0]
	adds r4, #0xa
	adds r1, r7, r4
	movs r0, #0x20
	strh r0, [r1]
	adds r5, #2
	adds r1, r7, r5
	movs r0, #0xf
_080409D8:
	strh r0, [r1]
	movs r0, #0x43
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040A08
	bl Script_GetValue
	movs r2, #0xc4
	lsls r2, r2, #2
	adds r1, r7, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r3, _08040A04 @ =0x00000311
	adds r1, r7, r3
	strb r0, [r1]
	b _08040A18
	.align 2, 0
_080409FC: .4byte 0x000002FA
_08040A00: .4byte 0x00000306
_08040A04: .4byte 0x00000311
_08040A08:
	movs r4, #0xc4
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r1, #2
	strb r1, [r0]
	ldr r5, _08040AAC @ =0x00000311
	adds r0, r7, r5
	strb r1, [r0]
_08040A18:
	movs r0, #0x6f
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r7, r3
	str r0, [r1]
	movs r4, #0xc8
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r1, #0
	str r1, [r0]
	movs r5, #0xc7
	lsls r5, r5, #2
	adds r0, r7, r5
	str r1, [r0]
	movs r0, #0x4f
	bl VM_SeekToKeyword
	mov r4, sb
	adds r4, #0xab
	movs r1, #0xa4
	adds r1, r1, r7
	mov sl, r1
	adds r2, r7, #0
	adds r2, #0xa5
	str r2, [sp, #0x30]
	adds r3, r7, #0
	adds r3, #0xa6
	str r3, [sp, #0x34]
	adds r5, r7, #0
	adds r5, #0xbc
	str r5, [sp, #0x44]
	adds r1, r7, #0
	adds r1, #0xa8
	str r1, [sp, #0x38]
	ldr r2, _08040AB0 @ =0x0000081C
	adds r2, r7, r2
	str r2, [sp, #0x54]
	mov r3, sb
	adds r3, #0xa3
	str r3, [sp, #0x3c]
	mov r5, sb
	adds r5, #0xf8
	str r5, [sp, #0x48]
	mov r1, sb
	adds r1, #0x8c
	str r1, [sp, #0x2c]
	mov r2, sb
	adds r2, #0xa9
	str r2, [sp, #0x40]
	adds r3, #0x59
	str r3, [sp, #0x4c]
	movs r5, #0x80
	lsls r5, r5, #1
	add r5, sb
	str r5, [sp, #0x50]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r1, r7, r1
	str r1, [sp, #0x58]
	cmp r0, #0
	beq _08040ADE
	movs r5, #0
	b _08040AD2
	.align 2, 0
_08040AAC: .4byte 0x00000311
_08040AB0: .4byte 0x0000081C
_08040AB4:
	bl Script_GetValue
	lsls r2, r5, #1
	movs r3, #0xc9
	lsls r3, r3, #2
	adds r1, r7, r3
	adds r1, r1, r2
	strh r0, [r1]
	movs r0, #0xc7
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r5, #1
_08040AD2:
	cmp r5, #3
	bgt _08040ADE
	bl VM_GetPC
	cmp r0, #0
	bne _08040AB4
_08040ADE:
	ldr r2, _08040B14 @ =0x0000030A
	adds r1, r7, r2
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1]
	movs r3, #0xc3
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r1]
	str r6, [sp]
	mov r0, sb
	ldr r1, [sp, #0x24]
	mov r2, r8
	add r3, sp, #0x1c
	bl Boss_Init_08022a70
	ldrb r0, [r4]
	cmp r0, #0
	beq _08040B18
	movs r4, #0xb0
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
	b _08040B20
	.align 2, 0
_08040B14: .4byte 0x0000030A
_08040B18:
	movs r5, #0xb0
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0x40
_08040B20:
	strh r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r6, r7, r0
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	movs r0, #2
	str r0, [sp]
	movs r5, #0
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r2, sp, #0x1c
	str r2, [sp, #0xc]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, sb
	adds r1, r6, #0
	mov r2, r8
	movs r3, #0
	bl FUN_08022d24
	movs r0, #0x78
	mov r3, sl
	strb r5, [r3]
	ldr r6, [sp, #0x30]
	strb r5, [r6]
	ldr r1, [sp, #0x34]
	strb r5, [r1]
	ldr r2, [sp, #0x44]
	str r5, [r2]
	ldr r3, [sp, #0x38]
	strb r4, [r3]
	ldr r6, [sp, #0x54]
	strh r0, [r6]
	ldr r0, _08040BE0 @ =FUN_0803e6b0
	ldr r1, [sp, #0x3c]
	strb r4, [r1]
	ldr r2, [sp, #0x48]
	str r0, [r2]
	ldr r3, [sp, #0x2c]
	str r5, [r3]
	ldr r5, [sp, #0x40]
	strb r4, [r5]
	ldr r0, _08040BE4 @ =FUN_080401ec
	ldr r6, [sp, #0x4c]
	str r0, [r6]
	ldr r0, _08040BE8 @ =FUN_080401a8
	ldr r1, [sp, #0x50]
	str r0, [r1]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r4, r7, r2
	ldrh r3, [r4]
	mov r0, sb
	ldr r1, [sp, #0x28]
	adds r2, r1, #0
	bl FUN_08022b2c
	adds r0, r7, #0
	bl FUN_0803cca4
	ldrh r1, [r4]
	adds r0, r7, #0
	bl FUN_0803cdf8
	adds r0, r7, #0
	bl FUN_0803cd4c
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040BEC
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r2, r0, #0
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08022fac
	b _08040BF6
	.align 2, 0
_08040BE0: .4byte FUN_0803e6b0
_08040BE4: .4byte FUN_080401ec
_08040BE8: .4byte FUN_080401a8
_08040BEC:
	mov r0, sb
	movs r1, #0
	movs r2, #0
	bl FUN_08022fac
_08040BF6:
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08040C1C
	movs r5, #0
	mov r4, sb
	adds r4, #0xe8
	b _08040C10
_08040C08:
	bl Script_GetValue
	stm r4!, {r0}
	adds r5, #1
_08040C10:
	cmp r5, #3
	bgt _08040C1C
	bl VM_GetPC
	cmp r0, #0
	bne _08040C08
_08040C1C:
	adds r0, r7, #0
	bl FUN_0803ce8c
	movs r3, #0xeb
	lsls r3, r3, #2
	adds r4, r7, r3
	movs r5, #0xdb
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r0, #0x40
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0xc8
	lsls r0, r0, #5
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r0, #6
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	movs r0, #0
	str r0, [sp, #0x18]
	adds r0, r4, #0
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_08013ba8
	ldr r1, _08040CC4 @ =0x00001C1B
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08013c94
	ldr r0, _08040CC8 @ =0x03003584
	ldr r0, [r0]
	movs r1, #0x99
	lsls r1, r1, #6
	adds r6, r0, r1
	movs r2, #0x83
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r5, #0xf
_08040C6E:
	adds r0, r6, #0
	adds r1, r4, #0
	ldr r2, _08040CCC @ =0x04000008
	bl CpuSet
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _08040C6E
	adds r0, r7, #0
	bl FUN_0803c1bc
	ldr r1, _08040CC8 @ =0x03003584
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r5, #0xf
_08040C96:
	adds r0, r6, #0
	adds r1, r4, #0
	ldr r2, _08040CCC @ =0x04000008
	bl CpuSet
	adds r6, #0x20
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _08040C96
	adds r0, r7, #0
	bl FUN_0803c1bc
	adds r1, r0, #0
	cmp r1, #0
	bne _08040CD0
	movs r4, #0x83
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r5, [sp, #0x58]
	str r0, [r5]
	b _08040CDC
	.align 2, 0
_08040CC4: .4byte 0x00001C1B
_08040CC8: .4byte 0x03003584
_08040CCC: .4byte 0x04000008
_08040CD0:
	ldr r0, _08040D1C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r6, [sp, #0x58]
	str r0, [r6]
_08040CDC:
	movs r0, #0xdb
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r0, r7, #0
	bl FUN_0803c6f0
	ldr r2, _08040D20 @ =0x00000818
	adds r1, r7, r2
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	ldr r3, _08040D24 @ =0x0000081A
	adds r1, r7, r3
	movs r0, #7
	strh r0, [r1]
	bl FUN_0805e67c
	ldr r4, _08040D28 @ =0x00000954
	adds r1, r7, r4
	str r0, [r1]
	cmp r0, #0
	beq _08040D30
	movs r0, #0x78
	bl FUN_0805ee80
	ldr r5, _08040D2C @ =0x00000958
	adds r1, r7, r5
	str r0, [r1]
	cmp r0, #0
	beq _08040D30
	movs r0, #0
	b _08040D34
	.align 2, 0
_08040D1C: .4byte 0x03003584
_08040D20: .4byte 0x00000818
_08040D24: .4byte 0x0000081A
_08040D28: .4byte 0x00000954
_08040D2C: .4byte 0x00000958
_08040D30:
	movs r0, #1
	rsbs r0, r0, #0
_08040D34:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start BossShadeMan_Create
BossShadeMan_Create: @ 0x08040D44
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #7
	bl FUN_08022a2c
	adds r4, r0, #0
	cmp r4, #0
	bne _08040D8E
	ldr r1, _08040D80 @ =0x0000095C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08040D8C
	ldr r1, _08040D84 @ =BossShadeMan_Update
	ldr r2, _08040D88 @ =BossShadeMan_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl BossShadeMan_Init
	cmp r0, #0
	bge _08040D8C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08040D8E
	.align 2, 0
_08040D80: .4byte 0x0000095C
_08040D84: .4byte BossShadeMan_Update
_08040D88: .4byte BossShadeMan_Destroy
_08040D8C:
	adds r0, r4, #0
_08040D8E:
	pop {r4, r5}
	pop {r1}
	bx r1

