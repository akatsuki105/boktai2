	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08016fd8
FUN_08016fd8: @ 0x08016FD8
	ldr r1, _08016FE0 @ =0x0300006C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08016FE0: .4byte 0x0300006C

	thumb_func_start FUN_08016fe4
FUN_08016fe4: @ 0x08016FE4
	movs r1, #0
	str r1, [r0]
	movs r2, #1
	strb r2, [r0, #4]
	strb r1, [r0, #5]
	strb r1, [r0, #6]
	str r1, [r0, #0xc]
	ldr r1, [r0, #0x2c]
	orrs r1, r2
	subs r2, #4
	ands r1, r2
	str r1, [r0, #0x2c]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08017000
FUN_08017000: @ 0x08017000
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r6, #0x24
	adds r5, r0, #0
	adds r5, #0x44
	adds r7, r0, #0
	adds r7, #0x18
	ldrh r0, [r0, #0x18]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801702A
	asrs r0, r0, #8
	b _08017030
_0801702A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017030:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08017042
	asrs r0, r0, #8
	b _08017048
_08017042:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017048:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801705C
	asrs r0, r0, #8
	b _08017062
_0801705C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017062:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08017094 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	ldrh r0, [r6, #0x20]
	subs r0, #8
	strh r0, [r6, #0x20]
	ldrh r0, [r6, #0x22]
	subs r0, #8
	strh r0, [r6, #0x22]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08017094: .4byte 0x030047C8

	thumb_func_start FUN_08017098
FUN_08017098: @ 0x08017098
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _080170B0
	movs r0, #0
	strb r0, [r4, #5]
	ldr r0, [r4, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x2c]
_080170B0:
	ldr r0, [r4, #0xc]
	cmp r0, #2
	bhi _080170BC
	ldrh r0, [r4, #0x1a]
	adds r0, #0x10
	b _080170C0
_080170BC:
	ldrh r0, [r4, #0x1a]
	subs r0, #0x10
_080170C0:
	strh r0, [r4, #0x1a]
	adds r0, r4, #0
	bl FUN_08017000
	ldr r0, [r4, #0xc]
	cmp r0, #3
	bls _080170DA
	movs r0, #1
	movs r1, #0
	strb r0, [r4, #4]
	strb r0, [r4, #5]
	str r1, [r4, #0xc]
	b _080170DE
_080170DA:
	adds r0, #1
	str r0, [r4, #0xc]
_080170DE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080170e4
FUN_080170e4: @ 0x080170E4
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _080170FC
	movs r0, #0
	strb r0, [r4, #5]
	ldr r0, [r4, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x2c]
_080170FC:
	adds r0, r4, #0
	bl FUN_08017000
	ldr r0, [r4, #0xc]
	ldrh r1, [r4, #0x10]
	cmp r0, r1
	blo _08017156
	ldrb r2, [r4, #7]
	cmp r2, #0
	bne _08017134
	ldrb r0, [r4, #0x12]
	ldr r1, _08017124 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08017128
	movs r0, #6
	b _0801712A
	.align 2, 0
_08017124: .4byte 0x03002BE0
_08017128:
	movs r0, #5
_0801712A:
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r2, [r4, #0xc]
	b _0801715A
_08017134:
	cmp r2, #1
	bne _08017144
	movs r0, #2
	movs r1, #0
	strb r0, [r4, #4]
	strb r2, [r4, #5]
	str r1, [r4, #0xc]
	b _0801715A
_08017144:
	cmp r2, #3
	bne _0801715A
	movs r0, #6
	movs r1, #0
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r1, [r4, #0xc]
	b _0801715A
_08017156:
	adds r0, #1
	str r0, [r4, #0xc]
_0801715A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08017160
FUN_08017160: @ 0x08017160
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	adds r5, r4, #0
	adds r5, #0x24
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _08017190
	movs r2, #0
	strb r2, [r4, #5]
	ldr r0, [r5, #8]
	movs r1, #2
	orrs r0, r1
	str r0, [r5, #8]
	strh r2, [r5, #0x36]
	adds r0, r4, #0
	adds r0, #0x58
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_08017190:
	adds r6, r4, #0
	adds r6, #0x58
	ldrb r0, [r6]
	cmp r0, #8
	bls _0801719E
	subs r0, #8
	strb r0, [r6]
_0801719E:
	ldrb r0, [r6]
	adds r1, r4, #0
	adds r1, #0x59
	strb r0, [r1]
	ldrh r0, [r5, #0x36]
	adds r0, #0x10
	strh r0, [r5, #0x36]
	ldrh r0, [r4, #0x18]
	adds r0, #8
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1c]
	adds r0, #8
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	bl FUN_08017000
	ldrb r1, [r6]
	movs r0, #0x40
	subs r0, r0, r1
	asrs r0, r0, #3
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	ldr r0, [r4, #0xc]
	cmp r0, #7
	bls _080171E6
	adds r0, r4, #0
	bl FUN_08016fe4
	movs r1, #1
	mov r0, r8
	lsls r1, r0
	ldr r0, [r7, #0x18]
	bics r0, r1
	str r0, [r7, #0x18]
	b _080171EA
_080171E6:
	adds r0, #1
	str r0, [r4, #0xc]
_080171EA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080171f4
FUN_080171f4: @ 0x080171F4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0
	ldrb r0, [r7, #5]
	cmp r0, #0
	beq _08017210
	movs r0, #0
	strb r0, [r7, #5]
	ldr r0, [r7, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x2c]
_08017210:
	ldrb r0, [r7, #7]
	cmp r0, #3
	bne _08017228
	ldr r0, [r7, #0xc]
	cmp r0, #3
	bhi _08017222
	ldrh r0, [r7, #0x1a]
	adds r0, #0x40
	b _08017238
_08017222:
	ldrh r0, [r7, #0x1a]
	subs r0, #4
	b _08017238
_08017228:
	ldr r0, [r7, #0xc]
	cmp r0, #4
	bhi _08017234
	ldrh r0, [r7, #0x1a]
	adds r0, #0x40
	b _08017238
_08017234:
	ldrh r0, [r7, #0x1a]
	subs r0, #8
_08017238:
	strh r0, [r7, #0x1a]
	adds r0, r7, #0
	bl FUN_08017000
	ldrb r0, [r7, #7]
	cmp r0, #3
	bne _080172A8
	ldr r0, [r7, #0xc]
	cmp r0, #3
	bls _0801728C
	ldr r0, _0801729C @ =0x0203B400
	mov r8, r0
	ldr r4, _080172A0 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r6, _080172A4 @ =0x000003FF
	ands r1, r6
	str r1, [r4]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	adds r3, r7, #0
	adds r3, #0x44
	ldrh r0, [r3]
	subs r0, #1
	movs r5, #3
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r6
	str r1, [r4]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	adds r2, r7, #0
	adds r2, #0x46
	ldrh r0, [r2]
	subs r0, #1
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_0801728C:
	ldrb r0, [r7, #7]
	cmp r0, #3
	bne _080172A8
	ldr r0, [r7, #0xc]
	cmp r0, #8
	bls _080172BC
	b _080172AE
	.align 2, 0
_0801729C: .4byte 0x0203B400
_080172A0: .4byte 0x030046B8
_080172A4: .4byte 0x000003FF
_080172A8:
	ldr r0, [r7, #0xc]
	cmp r0, #7
	bls _080172BC
_080172AE:
	movs r0, #4
	movs r1, #0
	strb r0, [r7, #4]
	movs r0, #1
	strb r0, [r7, #5]
	str r1, [r7, #0xc]
	b _080172C0
_080172BC:
	adds r0, #1
	str r0, [r7, #0xc]
_080172C0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080172cc
FUN_080172cc: @ 0x080172CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	adds r6, r4, #0
	adds r6, #0x24
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _08017306
	movs r2, #0
	strb r2, [r4, #5]
	ldr r0, [r4, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x2c]
	ldr r0, [r6, #8]
	movs r1, #2
	orrs r0, r1
	str r0, [r6, #8]
	strh r2, [r6, #0x36]
	adds r0, r4, #0
	adds r0, #0x58
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_08017306:
	adds r5, r4, #0
	adds r5, #0x58
	ldrb r0, [r5]
	cmp r0, #0x10
	bls _08017314
	subs r0, #0x10
	strb r0, [r5]
_08017314:
	ldrh r0, [r4, #0x1a]
	adds r0, #0x40
	strh r0, [r4, #0x1a]
	adds r0, r4, #0
	bl FUN_08017000
	ldrb r1, [r5]
	movs r0, #0x40
	subs r0, r0, r1
	asrs r0, r0, #3
	ldrh r1, [r6, #0x20]
	adds r0, r0, r1
	strh r0, [r6, #0x20]
	ldr r0, [r4, #0xc]
	cmp r0, #3
	bls _08017348
	adds r0, r4, #0
	bl FUN_08016fe4
	movs r1, #1
	mov r0, r8
	lsls r1, r0
	ldr r0, [r7, #0x18]
	bics r0, r1
	str r0, [r7, #0x18]
	b _0801734C
_08017348:
	adds r0, #1
	str r0, [r4, #0xc]
_0801734C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08017358
FUN_08017358: @ 0x08017358
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp, #0x10]
	adds r5, r1, #0
	str r2, [sp, #0x14]
	movs r0, #0x24
	adds r0, r0, r5
	mov ip, r0
	ldrb r0, [r5, #5]
	cmp r0, #0
	beq _0801739E
	movs r2, #0
	strb r2, [r5, #5]
	ldr r0, [r5, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x2c]
	mov r1, ip
	ldr r0, [r1, #8]
	movs r1, #2
	orrs r0, r1
	mov r1, ip
	str r0, [r1, #8]
	strh r2, [r1, #0x36]
	adds r0, r5, #0
	adds r0, #0x58
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_0801739E:
	ldr r2, [r5, #0xc]
	mov r8, r2
	movs r0, #0x10
	mov r1, r8
	subs r1, r0, r1
	mov sl, r1
	ldrb r0, [r5, #7]
	cmp r0, #0
	bne _08017410
	ldrb r0, [r5, #0x12]
	ldr r1, _080173DC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r6, sp
	adds r7, r0, #0
	adds r7, #0x2c
	ldrh r0, [r0, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080173E0
	asrs r0, r0, #8
	b _080173E6
	.align 2, 0
_080173DC: .4byte 0x03002BE0
_080173E0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080173E6:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080173F8
	asrs r0, r0, #8
	b _080173FE
_080173F8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080173FE:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0801745E
	b _08017462
_08017410:
	mov r6, sp
	ldr r2, [r5, #0x20]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08017430
	asrs r0, r0, #8
	b _08017436
_08017430:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017436:
	strh r0, [r6]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08017448
	asrs r0, r0, #8
	b _0801744E
_08017448:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801744E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08017462
_0801745E:
	asrs r0, r0, #8
	b _08017468
_08017462:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017468:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _080174AC @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	adds r7, r3, #0
	add r4, sp, #8
	adds r6, r5, #0
	adds r6, #0x18
	ldrh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	mov sb, r4
	cmp r0, #0
	blt _080174B0
	asrs r0, r0, #8
	b _080174B6
	.align 2, 0
_080174AC: .4byte 0x030047C8
_080174B0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080174B6:
	strh r0, [r4]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080174C8
	asrs r0, r0, #8
	b _080174CE
_080174C8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080174CE:
	adds r3, r0, #0
	movs r2, #2
	ldrsh r1, [r6, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080174E2
	asrs r0, r0, #8
	b _080174E8
_080174E2:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080174E8:
	subs r2, r3, r0
	strh r2, [r4, #2]
	adds r3, r3, r0
	strh r3, [r4, #4]
	ldrh r0, [r4]
	ldrh r1, [r7]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r4]
	ldrh r0, [r7, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r4, #2]
	ldrh r0, [r7, #4]
	subs r3, r3, r0
	strh r3, [r4, #4]
	mov r1, sp
	ldrh r0, [r1, #2]
	subs r0, #4
	strh r0, [r1, #2]
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	mov r1, sl
	muls r1, r0, r1
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, r1, r0
	cmp r0, #0
	blt _08017530
	asrs r0, r0, #4
	b _08017536
_08017530:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_08017536:
	mov r1, ip
	strh r0, [r1, #0x20]
	mov r2, sb
	movs r1, #2
	ldrsh r0, [r2, r1]
	mov r1, sl
	muls r1, r0, r1
	mov r0, sp
	movs r2, #2
	ldrsh r0, [r0, r2]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, r1, r0
	cmp r0, #0
	blt _0801755A
	asrs r0, r0, #4
	b _08017560
_0801755A:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_08017560:
	mov r1, ip
	strh r0, [r1, #0x22]
	mov r2, ip
	adds r2, #0x34
	ldrb r0, [r2]
	cmp r0, #0x20
	bls _08017572
	subs r0, #2
	strb r0, [r2]
_08017572:
	ldrb r0, [r2]
	mov r1, ip
	adds r1, #0x35
	strb r0, [r1]
	mov r1, ip
	ldrh r0, [r1, #0x36]
	adds r0, #8
	strh r0, [r1, #0x36]
	ldrh r1, [r1, #0x20]
	subs r1, #8
	ldrb r2, [r2]
	movs r0, #0x40
	subs r0, r0, r2
	asrs r0, r0, #3
	adds r1, r1, r0
	mov r2, ip
	strh r1, [r2, #0x20]
	ldrh r0, [r2, #0x22]
	subs r0, #8
	strh r0, [r2, #0x22]
	ldr r0, [r5, #0xc]
	cmp r0, #0xf
	bls _08017604
	ldrb r0, [r5, #6]
	cmp r0, #0
	bne _080175E0
	ldr r1, [r5, #8]
	adds r0, r1, #0
	subs r0, #0x40
	cmp r0, #3
	bhi _080175BC
	ldr r0, _080175B8 @ =0x00000183
	bl PlaySound_0824078c
	b _080175EA
	.align 2, 0
_080175B8: .4byte 0x00000183
_080175BC:
	adds r0, r1, #0
	bl IsValuable
	cmp r0, #1
	bne _080175D4
	ldr r0, _080175D0 @ =0x00000123
	bl PlaySound_0824078c
	b _080175EA
	.align 2, 0
_080175D0: .4byte 0x00000123
_080175D4:
	ldr r0, _080175DC @ =0x00000111
	bl PlaySound_0824078c
	b _080175EA
	.align 2, 0
_080175DC: .4byte 0x00000111
_080175E0:
	cmp r0, #3
	beq _080175EA
	ldr r0, _08017600 @ =0x00000123
	bl PlaySound_0824078c
_080175EA:
	adds r0, r5, #0
	bl FUN_08016fe4
	movs r1, #1
	ldr r0, [sp, #0x14]
	lsls r1, r0
	ldr r2, [sp, #0x10]
	ldr r0, [r2, #0x18]
	bics r0, r1
	str r0, [r2, #0x18]
	b _08017608
	.align 2, 0
_08017600: .4byte 0x00000123
_08017604:
	adds r0, #1
	str r0, [r5, #0xc]
_08017608:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity08017750_Update
Entity08017750_Update: @ 0x08017618
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r5, #0
	ldr r1, _08017668 @ =0x085AA92C
	mov r8, r1
	adds r4, r7, #0
	adds r4, #0x40
	adds r6, r7, #0
	adds r6, #0x3c
_0801762E:
	movs r2, #1
	lsls r2, r5
	ldr r1, [r7, #0x18]
	ands r1, r2
	cmp r1, #0
	beq _08017652
	ldrb r1, [r4]
	cmp r1, #6
	bhi _08017652
	adds r0, r1, #0
	lsls r0, r0, #2
	add r0, r8
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl _call_via_r3
_08017652:
	adds r4, #0x84
	adds r6, #0x84
	adds r5, #1
	cmp r5, #7
	ble _0801762E
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08017668: .4byte 0x085AA92C

	thumb_func_start Entity08017750_Destroy
Entity08017750_Destroy: @ 0x0801766C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x60
	movs r5, #7
_08017674:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x84
	subs r5, #1
	cmp r5, #0
	bge _08017674
	movs r2, #0
	ldr r1, _08017690 @ =0x0300006C
	str r2, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08017690: .4byte 0x0300006C

	thumb_func_start Entity08017750_Init
Entity08017750_Init: @ 0x08017694
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _080176BC @ =0x0300006C
	str r7, [r0]
	ldr r0, _080176C0 @ =0x0000CB05
	ldr r1, _080176C4 @ =0x00005D04
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _080176C8
	movs r0, #1
	rsbs r0, r0, #0
	b _0801773A
	.align 2, 0
_080176BC: .4byte 0x0300006C
_080176C0: .4byte 0x0000CB05
_080176C4: .4byte 0x00005D04
_080176C8:
	adds r1, r7, #0
	adds r1, #0x1c
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r5, r7, #0
	adds r5, #0x1c
	adds r0, r5, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r0, #0
	str r0, [r7, #0x18]
	add r4, sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801774C @ =0x05000002
	bl CpuSet
	mov sb, r5
	mov sl, r4
	movs r6, #0
	movs r5, #1
	mov r8, r5
	adds r4, r7, #0
	adds r4, #0x60
	adds r5, r7, #0
	adds r5, #0x3c
	movs r7, #7
_0801770C:
	str r6, [r5]
	mov r0, r8
	strb r0, [r5, #4]
	strb r6, [r5, #6]
	str r6, [r5, #0xc]
	mov r3, r8
	str r3, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	movs r3, #0x11
	bl MainSprite_Add
	adds r4, #0x84
	adds r5, #0x84
	subs r7, #1
	cmp r7, #0
	bge _0801770C
_0801773A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801774C: .4byte 0x05000002

	thumb_func_start Entity08017750_Create
Entity08017750_Create: @ 0x08017750
	push {r4, lr}
	ldr r0, _08017784 @ =0x0300006C
	ldr r0, [r0]
	cmp r0, #0
	bne _08017796
	ldr r1, _08017788 @ =0x0000045C
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08017794
	ldr r1, _0801778C @ =Entity08017750_Update
	ldr r2, _08017790 @ =Entity08017750_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity08017750_Init
	cmp r0, #0
	bge _08017794
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08017796
	.align 2, 0
_08017784: .4byte 0x0300006C
_08017788: .4byte 0x0000045C
_0801778C: .4byte Entity08017750_Update
_08017790: .4byte Entity08017750_Destroy
_08017794:
	adds r0, r4, #0
_08017796:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801779c
FUN_0801779c: @ 0x0801779C
	push {lr}
	ldr r0, _080177B0 @ =0x0300006C
	ldr r0, [r0]
	cmp r0, #0
	bne _080177AA
	bl Entity08017750_Create
_080177AA:
	pop {r1}
	bx r1
	.align 2, 0
_080177B0: .4byte 0x0300006C

	thumb_func_start FUN_080177b4
FUN_080177b4: @ 0x080177B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	mov r8, r1
	str r2, [sp, #4]
	mov sl, r3
	ldr r7, [sp, #0x38]
	bl FUN_0801779c
	mov sb, r0
	ldr r4, _08017818 @ =0x00FFFFFF
	ands r4, r7
	ldr r1, [sp]
	lsls r0, r1, #0x1c
	orrs r4, r0
	movs r5, #0
	movs r2, #1
	rsbs r2, r2, #0
	str r2, [sp, #8]
	movs r1, #0
	movs r6, #1
	mov r0, sb
	ldr r3, [r0, #0x18]
	mov r2, sb
	adds r2, #0x3c
_080177EE:
	adds r0, r6, #0
	lsls r0, r1
	ands r0, r3
	cmp r0, #0
	bne _08017806
	adds r5, r2, #0
	str r1, [sp, #8]
	cmp r7, #0
	beq _08017806
	ldr r0, [r5]
	cmp r0, r4
	beq _0801781C
_08017806:
	adds r2, #0x84
	adds r1, #1
	cmp r1, #7
	ble _080177EE
_0801780E:
	cmp r5, #0
	bne _08017832
	movs r0, #1
	rsbs r0, r0, #0
	b _08017996
	.align 2, 0
_08017818: .4byte 0x00FFFFFF
_0801781C:
	adds r0, r5, #0
	bl FUN_08016fe4
	adds r1, r6, #0
	mov r2, r8
	lsls r1, r2
	mov r2, sb
	ldr r0, [r2, #0x18]
	bics r0, r1
	str r0, [r2, #0x18]
	b _0801780E
_08017832:
	str r4, [r5]
	movs r2, #0
	mov r0, sl
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x12]
	ldr r1, _08017864 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _0801784A
	strb r2, [r5, #0x12]
_0801784A:
	ldr r0, [sp, #0x34]
	strh r0, [r5, #0x10]
	mov r1, sp
	ldrb r1, [r1, #4]
	strb r1, [r5, #7]
	ldrb r1, [r5, #7]
	cmp r1, #1
	beq _08017878
	cmp r1, #1
	bgt _08017868
	cmp r1, #0
	beq _08017872
	b _0801788E
	.align 2, 0
_08017864: .4byte 0x03002BE0
_08017868:
	cmp r1, #2
	beq _08017880
	cmp r1, #3
	beq _08017886
	b _0801788E
_08017872:
	movs r0, #3
	strb r0, [r5, #4]
	b _08017888
_08017878:
	movs r0, #0
	strb r0, [r5, #4]
	strb r1, [r5, #5]
	b _0801788C
_08017880:
	movs r0, #3
	strb r0, [r5, #4]
	b _08017888
_08017886:
	strb r1, [r5, #4]
_08017888:
	movs r0, #1
	strb r0, [r5, #5]
_0801788C:
	str r2, [r5, #0xc]
_0801788E:
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r5, #6]
	mov r0, r8
	str r0, [r5, #8]
	ldrb r0, [r5, #6]
	cmp r0, #1
	beq _080178B8
	cmp r0, #1
	bgt _080178A8
	cmp r0, #0
	beq _080178B2
	b _080178C8
_080178A8:
	cmp r0, #2
	beq _080178BC
	cmp r0, #3
	beq _080178C2
	b _080178C8
_080178B2:
	mov r2, r8
	adds r2, #0x68
	b _080178CA
_080178B8:
	mov r2, r8
	b _080178CA
_080178BC:
	mov r2, r8
	adds r2, #0x43
	b _080178CA
_080178C2:
	mov r2, r8
	adds r2, #0xb6
	b _080178CA
_080178C8:
	movs r2, #0x68
_080178CA:
	adds r0, r5, #0
	adds r0, #0x24
	mov r1, sb
	adds r1, #0x1c
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r5, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x2c]
	ldr r2, [sp, #0x2c]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r0, [sp, #0x30]
	str r0, [r5, #0x20]
	adds r6, r5, #0
	adds r6, #0x44
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r7, r6, #0
	cmp r0, #0
	blt _08017916
	asrs r0, r0, #8
	b _0801791C
_08017916:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801791C:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801792E
	asrs r0, r0, #8
	b _08017934
_0801792E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017934:
	adds r4, r0, #0
	ldr r0, [sp, #0x2c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801794A
	asrs r0, r0, #8
	b _08017950
_0801794A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017950:
	subs r2, r4, r0
	strh r2, [r6, #2]
	adds r4, r4, r0
	strh r4, [r6, #4]
	ldr r3, _080179A8 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	ldrh r0, [r7]
	subs r0, #8
	strh r0, [r7]
	adds r1, r5, #0
	adds r1, #0x46
	ldrh r0, [r1]
	subs r0, #8
	strh r0, [r1]
	ldr r0, [sp, #8]
	cmp r0, #0
	blt _08017994
	movs r1, #1
	lsls r1, r0
	mov r2, sb
	ldr r0, [r2, #0x18]
	orrs r0, r1
	str r0, [r2, #0x18]
_08017994:
	movs r0, #0
_08017996:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080179A8: .4byte 0x030047C8

