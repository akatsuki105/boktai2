	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0802326c
FUN_0802326c: @ 0x0802326C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	mov ip, r0
	ldr r6, _08023304 @ =0x0203B400
	ldr r5, _08023308 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r4, _0802330C @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r3, [r0]
	movs r0, #0x7f
	ands r3, r0
	mov r0, ip
	adds r0, #0x50
	ldrh r0, [r0]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08023310 @ =0xFFFF0000
	mov r8, r2
	ldr r2, [sp, #0x10]
	mov r7, r8
	ands r2, r7
	orrs r2, r0
	str r2, [sp, #0x10]
	adds r1, #1
	ands r1, r4
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	mov r4, ip
	adds r4, #0x52
	movs r0, #0x1f
	ands r1, r0
	ldrh r4, [r4]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	ldr r0, _08023314 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r0, ip
	adds r0, #0x54
	subs r3, #0x7f
	ldrh r0, [r0]
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #0x14]
	movs r0, #0xc
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015d3c
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023304: .4byte 0x0203B400
_08023308: .4byte 0x030046B8
_0802330C: .4byte 0x000003FF
_08023310: .4byte 0xFFFF0000
_08023314: .4byte 0x0000FFFF

	thumb_func_start FUN_08023318
FUN_08023318: @ 0x08023318
	push {r4, lr}
	bl FUN_08022a3c
	adds r4, r0, #0
	cmp r4, #0
	beq _08023378
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0802333E
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, _08023380 @ =0x000001C3
	bl PlaySound_082406e0
_0802333E:
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _08023352
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_08023352:
	movs r0, #0x62
	bl prepare_08231510
	cmp r0, #0
	beq _08023364
	ldr r0, _08023384 @ =0x00000155
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08023364:
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _08023378
	movs r0, #0xab
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08023378:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08023380: .4byte 0x000001C3
_08023384: .4byte 0x00000155

	thumb_func_start FUN_08023388
FUN_08023388: @ 0x08023388
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _080233D4 @ =0x0000026A
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r4, [r0]
	ldr r3, _080233D8 @ =0x00000266
	adds r0, r5, r3
	ldrh r2, [r0]
	movs r6, #0x99
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrh r3, [r0]
	ldr r0, _080233DC @ =0x0000C144
	cmp r1, r0
	bne _0802343E
	cmp r2, #0
	beq _080233E8
	ldr r1, _080233E0 @ =0x085AAAC4
	movs r0, #3
	ands r4, r0
	lsls r4, r4, #1
	adds r1, r4, r1
	movs r6, #0
	ldrsh r0, [r1, r6]
	muls r0, r3, r0
	adds r1, r2, #0
	bl Div
	ldr r1, _080233E4 @ =0x085AAABC
	adds r4, r4, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r4, r1, r0
	b _080233F6
	.align 2, 0
_080233D4: .4byte 0x0000026A
_080233D8: .4byte 0x00000266
_080233DC: .4byte 0x0000C144
_080233E0: .4byte 0x085AAAC4
_080233E4: .4byte 0x085AAABC
_080233E8:
	ldr r1, _08023410 @ =0x085AAABC
	movs r0, #3
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r4, [r0, r3]
_080233F6:
	ldr r1, _08023414 @ =0x085B0A08
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08023418
	asrs r0, r0, #0xc
	b _0802341E
	.align 2, 0
_08023410: .4byte 0x085AAABC
_08023414: .4byte 0x085B0A08
_08023418:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802341E:
	movs r1, #0xad
	lsls r1, r1, #1
	adds r2, r5, r1
	strh r0, [r2]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x23
	bls _08023462
	movs r0, #0
	b _08023460
_0802343E:
	ldr r0, _08023450 @ =0x085B0A08
	adds r0, #0x80
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08023454
	asrs r0, r0, #0xc
	b _0802345A
	.align 2, 0
_08023450: .4byte 0x085B0A08
_08023454:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802345A:
	movs r6, #0xad
	lsls r6, r6, #1
	adds r1, r5, r6
_08023460:
	strh r0, [r1]
_08023462:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08023468
FUN_08023468: @ 0x08023468
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r7, r5, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r4, #6]
	ands r0, r1
	cmp r0, #0
	beq _08023486
	adds r0, r4, #0
	adds r0, #0x42
	ldrb r0, [r0]
	b _0802349E
_08023486:
	movs r3, #0x24
	ldrsh r0, [r6, r3]
	movs r2, #0x24
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r6, r3]
	movs r3, #0x28
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
_0802349E:
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08236524
	ldrh r1, [r6, #0x3e]
	movs r3, #0xa8
	lsls r3, r3, #3
	adds r0, r7, r3
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0xde
	ldrh r0, [r4, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x3e]
	ldr r1, [r4, #0x34]
	adds r0, r5, #0
	adds r0, #0xb4
	str r1, [r0]
	ldr r1, [r4, #0x38]
	adds r0, #4
	str r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080234D8:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080234dc
FUN_080234dc: @ 0x080234DC
	push {lr}
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r0, r1
	bl FUN_08236424
	pop {r0}
	bx r0

	thumb_func_start FUN_080234ec
FUN_080234ec: @ 0x080234EC
	push {lr}
	adds r2, r0, #0
	movs r0, #4
	ldrsh r1, [r2, r0]
	ldr r0, _08023508 @ =0x0000077F
	cmp r1, r0
	bgt _08023514
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _0802350C @ =0x0000067F
	cmp r1, r0
	bgt _08023510
	movs r0, #0
	b _0802352A
	.align 2, 0
_08023508: .4byte 0x0000077F
_0802350C: .4byte 0x0000067F
_08023510:
	movs r0, #1
	b _0802352A
_08023514:
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _08023524 @ =0x0000067F
	cmp r1, r0
	ble _08023528
	movs r0, #3
	b _0802352A
	.align 2, 0
_08023524: .4byte 0x0000067F
_08023528:
	movs r0, #2
_0802352A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08023530
FUN_08023530: @ 0x08023530
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0x48
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r6, _080235AC @ =0x085AAACC
	ldr r2, _080235B0 @ =0x00000167
	adds r2, r2, r7
	mov r8, r2
	ldrb r4, [r2]
	adds r4, #0x20
	movs r5, #0xff
	ands r4, r5
	asrs r4, r4, #6
	adds r4, #1
	movs r0, #3
	ands r4, r0
	adds r0, r7, #0
	adds r0, #0x50
	bl FUN_080234ec
	ldr r3, _080235B4 @ =0x0000016F
	adds r1, r7, r3
	lsls r4, r4, #1
	ldrb r1, [r1]
	adds r4, r4, r1
	lsls r0, r0, #3
	adds r4, r4, r0
	adds r4, r4, r6
	ldrb r1, [r4]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #0x21
	adds r2, r7, r3
	mov r0, r8
	ldrb r3, [r0]
	ldr r1, _080235B8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #0xc
	cmp r0, #0
	blt _080235BC
	asrs r1, r0, #0xc
	b _080235C2
	.align 2, 0
_080235AC: .4byte 0x085AAACC
_080235B0: .4byte 0x00000167
_080235B4: .4byte 0x0000016F
_080235B8: .4byte 0x085B0A08
_080235BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080235C2:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _080235E0 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x80
	lsls r0, r0, #5
	muls r0, r1, r0
	cmp r0, #0
	blt _080235E4
	asrs r0, r0, #0xc
	b _080235EA
	.align 2, 0
_080235E0: .4byte 0x085B0A08
_080235E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080235EA:
	strh r0, [r2, #4]
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r0, [r1]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r3, [r2, #2]
	adds r0, r0, r3
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	ldr r3, _0802363C @ =0x0000016F
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #9
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r3, #0x23
	adds r1, r7, r3
	strh r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08023670
	cmp r0, #1
	bgt _08023640
	cmp r0, #0
	beq _0802364A
	b _080236E2
	.align 2, 0
_0802363C: .4byte 0x0000016F
_08023640:
	cmp r0, #2
	beq _08023690
	cmp r0, #3
	beq _080236BA
	b _080236E2
_0802364A:
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r0, _08023658 @ =0x0000017F
	cmp r1, r0
	bgt _0802365C
	adds r0, #1
	b _08023664
	.align 2, 0
_08023658: .4byte 0x0000017F
_0802365C:
	movs r0, #0xb8
	lsls r0, r0, #4
	cmp r1, r0
	ble _08023666
_08023664:
	strh r0, [r2]
_08023666:
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r7, r0
	subs r0, #0x94
	b _080236E0
_08023670:
	movs r0, #0xc0
	lsls r0, r0, #4
	strh r0, [r2]
	movs r2, #0xca
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldr r0, _0802368C @ =0x0000017F
	cmp r2, r0
	bgt _080236D8
	adds r0, #1
	b _080236E0
	.align 2, 0
_0802368C: .4byte 0x0000017F
_08023690:
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _080236A0 @ =0x0000017F
	cmp r1, r0
	bgt _080236A4
	adds r0, #1
	b _080236AC
	.align 2, 0
_080236A0: .4byte 0x0000017F
_080236A4:
	movs r0, #0xb8
	lsls r0, r0, #4
	cmp r1, r0
	ble _080236AE
_080236AC:
	strh r0, [r2]
_080236AE:
	movs r2, #0xca
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0xc0
	lsls r0, r0, #4
	b _080236E0
_080236BA:
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r2]
	movs r3, #0xca
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0
	ldrsh r2, [r1, r0]
	ldr r0, _080236D4 @ =0x0000017F
	cmp r2, r0
	bgt _080236D8
	adds r0, #1
	b _080236E0
	.align 2, 0
_080236D4: .4byte 0x0000017F
_080236D8:
	movs r0, #0xb8
	lsls r0, r0, #4
	cmp r2, r0
	ble _080236E2
_080236E0:
	strh r0, [r1]
_080236E2:
	ldr r1, _08023734 @ =0x0000016F
	adds r1, r1, r7
	mov r8, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _08023778
	ldr r5, _08023738 @ =0x085AAACC
	ldr r2, _0802373C @ =0x00000167
	adds r6, r7, r2
	ldrb r4, [r6]
	adds r4, #0x20
	movs r0, #0xff
	ands r4, r0
	asrs r4, r4, #6
	adds r4, #1
	movs r0, #3
	ands r4, r0
	mov r0, sb
	adds r0, #8
	bl FUN_080234ec
	mov r3, r8
	ldrb r1, [r3]
	lsls r4, r4, #1
	adds r4, #1
	adds r1, r1, r4
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r1, r5
	ldrb r1, [r1]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _08023754
	cmp r0, #1
	bgt _08023740
	cmp r0, #0
	beq _0802374A
	b _08023778
	.align 2, 0
_08023734: .4byte 0x0000016F
_08023738: .4byte 0x085AAACC
_0802373C: .4byte 0x00000167
_08023740:
	cmp r0, #2
	beq _0802375E
	cmp r0, #3
	beq _08023768
	b _08023778
_0802374A:
	cmp r1, #1
	bne _08023772
	ldrb r0, [r6]
	adds r0, #0x40
	b _08023776
_08023754:
	cmp r1, #2
	bne _08023772
	ldrb r0, [r6]
	adds r0, #0x40
	b _08023776
_0802375E:
	cmp r1, #3
	bne _08023772
	ldrb r0, [r6]
	adds r0, #0x40
	b _08023776
_08023768:
	cmp r1, #0
	bne _08023772
	ldrb r0, [r6]
	adds r0, #0x40
	b _08023776
_08023772:
	ldrb r0, [r6]
	subs r0, #0x40
_08023776:
	strb r0, [r6]
_08023778:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08023784
FUN_08023784: @ 0x08023784
	movs r2, #0
	strh r1, [r0]
	strh r2, [r0, #2]
	bx lr

	thumb_func_start FUN_0802378c
FUN_0802378c: @ 0x0802378C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	mov r8, r0
	movs r5, #0xae
	lsls r5, r5, #2
	add r5, r8
	movs r6, #0
	mov sb, r6
	movs r7, #0x8e
	lsls r7, r7, #2
	add r7, r8
_080237A8:
	adds r4, r5, #0
	adds r4, #0xc
	adds r1, r5, #4
	mov r0, sb
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	ldr r2, _08023810 @ =0x05000002
	bl CpuSet
	movs r0, #2
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	movs r0, #0x9e
	lsls r0, r0, #2
	add r0, r8
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	movs r3, #1
	bl FUN_0822f4d8
	ldr r1, _08023814 @ =0x085AAAEC
	lsls r0, r6, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	mov r0, sb
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r3, #2
	bl FUN_082370cc
	adds r6, #1
	adds r5, #0x6c
	cmp r6, #4
	ble _080237A8
	movs r1, #0xb4
	lsls r1, r1, #1
	add r1, r8
	movs r0, #0
	strh r0, [r1]
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023810: .4byte 0x05000002
_08023814: .4byte 0x085AAAEC

	thumb_func_start FUN_08023818
FUN_08023818: @ 0x08023818
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0xae
	lsls r0, r0, #2
	adds r6, r7, r0
	movs r1, #4
	mov r8, r1
	adds r0, #4
	adds r5, r7, r0
_08023830:
	adds r4, r6, #0
	adds r4, #0xc
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r6, #4
	ldr r2, _080238A8 @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08023784
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x28]
	str r1, [r5, #0x2c]
	ldrh r0, [r5]
	ldrh r1, [r5, #0x28]
	adds r0, r0, r1
	strh r0, [r5, #0x28]
	ldrh r0, [r5, #2]
	ldrh r1, [r5, #0x2a]
	adds r0, r0, r1
	strh r0, [r5, #0x2a]
	ldrh r0, [r5, #4]
	ldrh r1, [r5, #0x2c]
	adds r0, r0, r1
	strh r0, [r5, #0x2c]
	ldr r0, [r5, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x10]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822a3f0
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	adds r5, #0x6c
	adds r6, #0x6c
	mov r1, r8
	cmp r1, #0
	bge _08023830
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #1
	strh r0, [r1]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080238A8: .4byte 0x05000002

	thumb_func_start FUN_080238ac
FUN_080238ac: @ 0x080238AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r1, #0
	ldrh r0, [r7, #6]
	adds r0, #0x30
	strh r0, [r7, #6]
	cmp r2, #4
	bne _080238D2
	ldrh r0, [r7, #4]
	subs r0, #0xa
	strh r0, [r7, #4]
	ldrh r0, [r7, #8]
	adds r0, #0xa
	strh r0, [r7, #8]
	b _080238E6
_080238D2:
	cmp r2, #0
	bne _080238DC
	ldrh r0, [r7, #4]
	adds r0, #6
	b _080238E4
_080238DC:
	cmp r2, #1
	bne _080238E6
	ldrh r0, [r7, #4]
	adds r0, #0xa
_080238E4:
	strh r0, [r7, #4]
_080238E6:
	ldrh r0, [r7, #2]
	movs r1, #3
	mov sl, r1
	mov r6, sl
	ands r6, r0
	cmp r6, #0
	bne _08023988
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, _080239A8 @ =0x0203B400
	mov ip, r2
	ldr r0, _080239AC @ =0x030046B8
	mov sb, r0
	ldr r2, [r0]
	adds r2, #1
	ldr r5, _080239B0 @ =0x000003FF
	ands r2, r5
	lsls r1, r2, #1
	add r1, ip
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080239B4 @ =0xFFFF0000
	mov r8, r1
	ldr r4, [sp, #0x10]
	ands r4, r1
	orrs r4, r0
	str r4, [sp, #0x10]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	add r0, ip
	ldrh r3, [r0]
	asrs r1, r4, #0x10
	adds r1, #0x80
	movs r0, #0x3f
	ands r3, r0
	adds r1, r1, r3
	lsls r1, r1, #0x10
	ldr r0, _080239B8 @ =0x0000FFFF
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r5
	mov r0, sb
	str r2, [r0]
	lsls r2, r2, #1
	add r2, ip
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	mov r2, r8
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x14]
	movs r2, #0xc0
	lsls r2, r2, #6
	movs r0, #0xc
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015d3c
_08023988:
	ldrh r0, [r7, #2]
	cmp r0, #0xa
	bls _08023996
	adds r0, r7, #0
	movs r1, #2
	bl FUN_08023784
_08023996:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080239A8: .4byte 0x0203B400
_080239AC: .4byte 0x030046B8
_080239B0: .4byte 0x000003FF
_080239B4: .4byte 0xFFFF0000
_080239B8: .4byte 0x0000FFFF

	thumb_func_start FUN_080239bc
FUN_080239bc: @ 0x080239BC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r7, r1, #0
	cmp r2, #4
	bne _080239E0
	ldrh r0, [r7, #6]
	adds r0, #0x10
	strh r0, [r7, #6]
	ldrh r0, [r7, #4]
	subs r0, #0xa
	strh r0, [r7, #4]
	ldrh r0, [r7, #8]
	adds r0, #0xa
	strh r0, [r7, #8]
	b _08023A00
_080239E0:
	cmp r2, #0
	bne _080239F0
	ldrh r0, [r7, #6]
	adds r0, #0x10
	strh r0, [r7, #6]
	ldrh r0, [r7, #4]
	adds r0, #6
	b _080239FE
_080239F0:
	cmp r2, #1
	bne _08023A00
	ldrh r0, [r7, #6]
	adds r0, #0x10
	strh r0, [r7, #6]
	ldrh r0, [r7, #4]
	adds r0, #0xa
_080239FE:
	strh r0, [r7, #4]
_08023A00:
	ldrh r0, [r7, #2]
	movs r1, #7
	mov ip, r1
	mov r2, ip
	ands r2, r0
	mov ip, r2
	cmp r2, #0
	bne _08023AA4
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r6, _08023ABC @ =0x0203B400
	ldr r0, _08023AC0 @ =0x030046B8
	mov sb, r0
	ldr r2, [r0]
	adds r2, #1
	ldr r5, _08023AC4 @ =0x000003FF
	ands r2, r5
	lsls r1, r2, #1
	adds r1, r1, r6
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08023AC8 @ =0xFFFF0000
	mov r8, r1
	ldr r4, [sp, #0x10]
	ands r4, r1
	orrs r4, r0
	str r4, [sp, #0x10]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r3, [r0]
	asrs r1, r4, #0x10
	adds r1, #0x80
	movs r0, #0x3f
	ands r3, r0
	adds r1, r1, r3
	lsls r1, r1, #0x10
	ldr r0, _08023ACC @ =0x0000FFFF
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r5
	mov r0, sb
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r6
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	mov r2, r8
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x14]
	movs r2, #0xc0
	lsls r2, r2, #6
	movs r0, #0xc
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, ip
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015d3c
_08023AA4:
	ldrh r0, [r7, #2]
	adds r2, r0, #0
	cmp r2, #0x13
	bhi _08023AD0
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _08023AE0
	ldr r0, [r7, #0x14]
	movs r1, #1
	orrs r0, r1
	b _08023AE8
	.align 2, 0
_08023ABC: .4byte 0x0203B400
_08023AC0: .4byte 0x030046B8
_08023AC4: .4byte 0x000003FF
_08023AC8: .4byte 0xFFFF0000
_08023ACC: .4byte 0x0000FFFF
_08023AD0:
	movs r1, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _08023AE0
	ldr r0, [r7, #0x14]
	orrs r0, r1
	b _08023AE8
_08023AE0:
	ldr r0, [r7, #0x14]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_08023AE8:
	str r0, [r7, #0x14]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x28
	bls _08023B02
	adds r0, r7, #0
	movs r1, #3
	bl FUN_08023784
	ldr r0, [r7, #0x14]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x14]
_08023B02:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08023b10
FUN_08023b10: @ 0x08023B10
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08023B96
	movs r2, #0xae
	lsls r2, r2, #2
	adds r5, r6, r2
	movs r7, #0
	adds r4, r5, #0
_08023B2E:
	movs r0, #0xc
	adds r0, r0, r5
	mov r8, r0
	ldrh r0, [r4]
	cmp r0, #1
	bne _08023B46
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl FUN_080238ac
	b _08023B54
_08023B46:
	cmp r0, #2
	bne _08023B54
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl FUN_080239bc
_08023B54:
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x2c]
	str r1, [r4, #0x30]
	ldrh r0, [r4, #4]
	ldrh r2, [r4, #0x2c]
	adds r0, r0, r2
	strh r0, [r4, #0x2c]
	ldrh r0, [r4, #6]
	ldrh r1, [r4, #0x2e]
	adds r0, r0, r1
	strh r0, [r4, #0x2e]
	ldrh r0, [r4, #8]
	ldrh r2, [r4, #0x30]
	adds r0, r0, r2
	strh r0, [r4, #0x30]
	mov r0, r8
	movs r2, #0x8e
	lsls r2, r2, #2
	adds r1, r6, r2
	bl FUN_082372cc
	adds r7, #1
	adds r4, #0x6c
	adds r5, #0x6c
	cmp r7, #4
	ble _08023B2E
_08023B96:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08023ba0
FUN_08023ba0: @ 0x08023BA0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08023BD2
	movs r0, #0xae
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r5, #4
_08023BB8:
	adds r0, r4, #0
	adds r0, #0xc
	bl FUN_0822f1c0
	subs r5, #1
	adds r4, #0x6c
	cmp r5, #0
	bge _08023BB8
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
_08023BD2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08023bd8
FUN_08023bd8: @ 0x08023BD8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r2, r0, #0
	cmp r1, #0
	bne _08023CBA
	movs r0, #0xb5
	lsls r0, r0, #1
	adds r7, r2, r0
	ldrh r0, [r7]
	cmp r0, #0
	bne _08023CB4
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, _08023CA0 @ =0x0203B400
	mov r8, r2
	ldr r6, _08023CA4 @ =0x030046B8
	ldr r2, [r6]
	adds r2, #1
	ldr r5, _08023CA8 @ =0x000003FF
	ands r2, r5
	lsls r1, r2, #1
	add r1, r8
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08023CAC @ =0xFFFF0000
	mov sb, r1
	ldr r4, [sp, #0x10]
	ands r4, r1
	orrs r4, r0
	str r4, [sp, #0x10]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	add r0, r8
	ldrh r3, [r0]
	asrs r1, r4, #0x10
	adds r1, #0x80
	movs r0, #0x3f
	ands r3, r0
	adds r1, r1, r3
	lsls r1, r1, #0x10
	ldr r0, _08023CB0 @ =0x0000FFFF
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r5
	str r2, [r6]
	lsls r2, r2, #1
	add r2, r8
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	mov r2, sb
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x14]
	movs r2, #0xc0
	lsls r2, r2, #6
	movs r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015d3c
	ldr r0, [r6]
	adds r0, #1
	ands r0, r5
	str r0, [r6]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #2
	strh r0, [r7]
	b _08023D6E
	.align 2, 0
_08023CA0: .4byte 0x0203B400
_08023CA4: .4byte 0x030046B8
_08023CA8: .4byte 0x000003FF
_08023CAC: .4byte 0xFFFF0000
_08023CB0: .4byte 0x0000FFFF
_08023CB4:
	subs r0, #1
	strh r0, [r7]
	b _08023D6E
_08023CBA:
	movs r0, #0xb5
	lsls r0, r0, #1
	adds r0, r0, r2
	mov sb, r0
	ldrh r0, [r0]
	adds r7, r0, #0
	cmp r7, #0
	bne _08023D68
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, _08023D5C @ =0x0203B400
	mov r8, r2
	ldr r6, _08023D60 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r5, _08023D64 @ =0x000003FF
	ands r1, r5
	lsls r2, r1, #1
	add r2, r8
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	add r2, sp, #0x10
	strh r0, [r2]
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	add r0, r8
	ldrh r3, [r0]
	adds r4, r2, #0
	ldrh r0, [r4, #2]
	adds r0, #0x80
	movs r2, #0x3f
	ands r3, r2
	adds r0, r0, r3
	strh r0, [r4, #2]
	adds r1, #1
	ands r1, r5
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r4, #4]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #4]
	movs r2, #0xc0
	lsls r2, r2, #6
	movs r0, #0xc
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015d3c
	ldr r0, [r6]
	adds r0, #1
	ands r0, r5
	str r0, [r6]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #1
	mov r1, sb
	strh r0, [r1]
	b _08023D6E
	.align 2, 0
_08023D5C: .4byte 0x0203B400
_08023D60: .4byte 0x030046B8
_08023D64: .4byte 0x000003FF
_08023D68:
	subs r0, #1
	mov r2, sb
	strh r0, [r2]
_08023D6E:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08023d7c
FUN_08023d7c: @ 0x08023D7C
	push {lr}
	adds r1, r0, #0
	adds r0, #0xa4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08023DC2
	adds r1, #0x50
	movs r0, #0
	ldrsh r2, [r1, r0]
	ldr r0, _08023D98 @ =0x0000011F
	cmp r2, r0
	bgt _08023D9C
	adds r0, #1
	b _08023DA4
	.align 2, 0
_08023D98: .4byte 0x0000011F
_08023D9C:
	movs r0, #0xbe
	lsls r0, r0, #4
	cmp r2, r0
	ble _08023DA6
_08023DA4:
	strh r0, [r1]
_08023DA6:
	movs r0, #4
	ldrsh r2, [r1, r0]
	ldr r0, _08023DB4 @ =0x0000021F
	cmp r2, r0
	bgt _08023DB8
	adds r0, #1
	b _08023DC0
	.align 2, 0
_08023DB4: .4byte 0x0000021F
_08023DB8:
	movs r0, #0xce
	lsls r0, r0, #4
	cmp r2, r0
	ble _08023DC2
_08023DC0:
	strh r0, [r1, #4]
_08023DC2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08023dc8
FUN_08023dc8: @ 0x08023DC8
	push {r4, lr}
	ldr r4, _08023DE4 @ =0x085AAAF6
	lsls r1, r1, #2
	adds r3, r1, r4
	ldrh r3, [r3]
	strh r3, [r0]
	strh r2, [r0, #2]
	adds r4, #2
	adds r1, r1, r4
	ldrh r1, [r1]
	strh r1, [r0, #4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08023DE4: .4byte 0x085AAAF6

	thumb_func_start FUN_08023de8
FUN_08023de8: @ 0x08023DE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08023E04
	b _08023FDA
_08023E04:
	bl FUN_080591f4
	cmp r0, #0xb
	ble _08023E0E
	b _08023FDA
_08023E0E:
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r3, sp, #8
	mov ip, r3
	ldrh r0, [r3, #4]
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08023EB4 @ =0xFFFF0000
	ldr r5, [sp, #0xc]
	ands r5, r4
	orrs r5, r0
	str r5, [sp, #0xc]
	ldr r0, _08023EB8 @ =0x0203B400
	mov sl, r0
	ldr r1, _08023EBC @ =0x030046B8
	mov sb, r1
	ldr r2, [r1]
	adds r2, #1
	ldr r3, _08023EC0 @ =0x000003FF
	mov r8, r3
	ands r2, r3
	lsls r0, r2, #1
	add r0, sl
	ldrh r3, [r0]
	add r0, sp, #8
	ldrh r1, [r0]
	subs r1, #0x40
	movs r6, #0x7f
	ands r3, r6
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	adds r2, #1
	mov r0, r8
	ands r2, r0
	mov r1, sb
	str r2, [r1]
	lsls r2, r2, #1
	add r2, sl
	ldrh r1, [r2]
	mov r2, ip
	ldrh r0, [r2, #4]
	subs r0, #0x40
	ands r1, r6
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r4, r5
	orrs r4, r0
	str r4, [sp, #0xc]
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08023EAE
	cmp r1, #0
	blt _08023EAE
	ldr r0, _08023EC4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08023EAE
	ldr r0, _08023EC8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08023ECC
_08023EAE:
	movs r4, #0
	b _08023EDA
	.align 2, 0
_08023EB4: .4byte 0xFFFF0000
_08023EB8: .4byte 0x0203B400
_08023EBC: .4byte 0x030046B8
_08023EC0: .4byte 0x000003FF
_08023EC4: .4byte 0x030046A8
_08023EC8: .4byte 0x030046AC
_08023ECC:
	ldr r0, _08023EEC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08023EDA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08023EF0
	adds r0, #4
	b _08023EFC
	.align 2, 0
_08023EEC: .4byte 0x030046A4
_08023EF0:
	ldr r0, _08023F10 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08023EFC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08023F14
	cmp r2, #2
	beq _08023F18
	b _08023F1C
	.align 2, 0
_08023F10: .4byte 0x030046A4
_08023F14:
	ldrb r0, [r5, #4]
	b _08023F1A
_08023F18:
	ldrb r0, [r5]
_08023F1A:
	subs r1, r1, r0
_08023F1C:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne _08023FDA
	add r1, sp, #8
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08023F4C
	cmp r1, #0
	blt _08023F4C
	ldr r0, _08023F50 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08023F4C
	ldr r0, _08023F54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08023F58
_08023F4C:
	movs r4, #0
	b _08023F66
	.align 2, 0
_08023F50: .4byte 0x030046A8
_08023F54: .4byte 0x030046AC
_08023F58:
	ldr r0, _08023F78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08023F66:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08023F7C
	adds r0, #4
	b _08023F88
	.align 2, 0
_08023F78: .4byte 0x030046A4
_08023F7C:
	ldr r0, _08023FEC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08023F88:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08023FDA
	ldr r2, _08023FF0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08023FF4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08023FF8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	ldr r4, _08023FFC @ =0x0000078E
	adds r0, r7, r4
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r4, #2
	adds r0, r7, r4
	movs r4, #0
	ldrsh r3, [r0, r4]
	ldr r4, _08024000 @ =0x00000792
	adds r0, r7, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp]
	add r0, sp, #8
	str r0, [sp, #4]
	movs r0, #1
	bl FUN_08059054
	movs r2, #0xaa
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_08023FDA:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023FEC: .4byte 0x030046A4
_08023FF0: .4byte 0x030046B8
_08023FF4: .4byte 0x000003FF
_08023FF8: .4byte 0x0203B400
_08023FFC: .4byte 0x0000078E
_08024000: .4byte 0x00000792

	thumb_func_start FUN_08024004
FUN_08024004: @ 0x08024004
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r2, r0, r3
	adds r0, #0x94
	strh r1, [r0]
	strh r1, [r2, #0x3c]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08024014
FUN_08024014: @ 0x08024014
	mov ip, r0
	movs r0, #0xcc
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0, #0x3c]
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r0, #0xee
	lsls r0, r0, #1
	add r0, ip
	strh r3, [r0]
	bx lr

	thumb_func_start FUN_08024030
FUN_08024030: @ 0x08024030
	push {r4, lr}
	sub sp, #8
	lsls r1, r1, #0x10
	ldr r4, _08024064 @ =0xFFFF0000
	lsls r2, r2, #0x10
	lsrs r1, r1, #0x10
	orrs r1, r2
	str r1, [sp]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r3
	str r1, [sp, #4]
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [sp]
	ldr r2, [sp, #4]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08024064: .4byte 0xFFFF0000

	thumb_func_start FUN_08024068
FUN_08024068: @ 0x08024068
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xa4
	movs r2, #0xc8
	movs r3, #0xa4
	bl FUN_08024030
	ldr r1, _080240AC @ =0x00000784
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _080240B0 @ =0x00000786
	adds r0, r4, r3
	movs r5, #0
	ldrsh r2, [r0, r5]
	adds r3, #2
	adds r0, r4, r3
	movs r5, #0
	ldrsh r3, [r0, r5]
	adds r0, r4, #0
	bl FUN_08024014
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r4, r4, r0
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r4, #0x38]
	orrs r0, r1
	str r0, [r4, #0x38]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080240AC: .4byte 0x00000784
_080240B0: .4byte 0x00000786

	thumb_func_start FUN_080240b4
FUN_080240b4: @ 0x080240B4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x40
	movs r2, #0x81
	movs r3, #0x40
	bl FUN_08024030
	ldr r1, _080240F8 @ =0x0000077E
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xf0
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r5, #0
	ldrsh r2, [r0, r5]
	adds r3, #2
	adds r0, r4, r3
	movs r5, #0
	ldrsh r3, [r0, r5]
	adds r0, r4, #0
	bl FUN_08024014
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r1, _080240FC @ =0xFFFBFFFF
	ldr r0, [r4, #0x38]
	ands r0, r1
	str r0, [r4, #0x38]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080240F8: .4byte 0x0000077E
_080240FC: .4byte 0xFFFBFFFF

	thumb_func_start FUN_08024100
FUN_08024100: @ 0x08024100
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x18
	mov sl, r0
	ldr r3, _080241D0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0xa4
	orrs r0, r2
	ldr r1, _080241D4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x14]
	ldr r6, _080241D8 @ =0x0203B400
	ldr r0, _080241DC @ =0x030046B8
	mov sb, r0
	ldr r0, [r0]
	adds r0, #1
	ldr r5, _080241E0 @ =0x000003FF
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
_080241D0: .4byte 0xFFFF0000
_080241D4: .4byte 0x0000FFFF
_080241D8: .4byte 0x0203B400
_080241DC: .4byte 0x030046B8
_080241E0: .4byte 0x000003FF

	thumb_func_start FUN_080241e4
FUN_080241e4: @ 0x080241E4
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r5, r4, r0
	ldr r2, _0802427C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _08024280 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _08024284 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r1, r4, r0
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08024288 @ =0x080234D9
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r1, _0802428C @ =0x0000077E
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xf0
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0
	str r0, [sp]
	ldr r0, _08024290 @ =0x00000782
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
_0802427C: .4byte 0xFFFF0000
_08024280: .4byte 0x0000FFFF
_08024284: .4byte 0x00002001
_08024288: .4byte 0x080234D9
_0802428C: .4byte 0x0000077E
_08024290: .4byte 0x00000782

	thumb_func_start FUN_08024294
FUN_08024294: @ 0x08024294
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0xf4
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r2, _08024314 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0xa4
	orrs r0, r3
	ldr r1, _08024318 @ =0x0000FFFF
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
	ldr r2, _0802431C @ =0x00005001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08024320 @ =FUN_08023468
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	movs r2, #0x81
	lsls r2, r2, #4
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #0x20
	bl FUN_08236514
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08024314: .4byte 0xFFFF0000
_08024318: .4byte 0x0000FFFF
_0802431C: .4byte 0x00005001
_08024320: .4byte FUN_08023468

	thumb_func_start FUN_08024324
FUN_08024324: @ 0x08024324
	ldr r1, _08024344 @ =0x0000054C
	adds r3, r0, r1
	movs r2, #0
	movs r1, #1
	strb r1, [r3]
	ldr r3, _08024348 @ =0x0000054D
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #1
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, _0802434C @ =0x0000054F
	adds r0, r0, r1
	strb r2, [r0]
	bx lr
	.align 2, 0
_08024344: .4byte 0x0000054C
_08024348: .4byte 0x0000054D
_0802434C: .4byte 0x0000054F

	thumb_func_start FUN_08024350
FUN_08024350: @ 0x08024350
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r5, #0
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
	movs r7, #0
	ldr r0, _08024374 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r0, r5, r2
	b _080244E6
	.align 2, 0
_08024374: .4byte 0x03002B4C
_08024378:
	ldr r0, _080243A8 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, r8
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #0xa
	bls _0802439E
	b _080244DA
_0802439E:
	lsls r0, r0, #2
	ldr r1, _080243AC @ =_080243B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080243A8: .4byte 0x03002B4C
_080243AC: .4byte _080243B0
_080243B0: @ jump table
	.4byte _080243DC @ case 0
	.4byte _08024420 @ case 1
	.4byte _080243F4 @ case 2
	.4byte _080244DA @ case 3
	.4byte _080244DA @ case 4
	.4byte _080244DA @ case 5
	.4byte _080244DA @ case 6
	.4byte _08024474 @ case 7
	.4byte _0802448A @ case 8
	.4byte _080244A0 @ case 9
	.4byte _080244BC @ case 10
_080243DC:
	movs r2, #2
	movs r1, #0
	adds r0, r5, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	b _080244D2
_080243F4:
	ldrb r0, [r4, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r3, #0
	strb r0, [r1]
	movs r1, #2
	movs r2, #1
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	subs r0, #0x14
	strb r2, [r0]
	b _080244DA
_08024420:
	ldrh r0, [r4, #8]
	adds r1, r5, #0
	adds r1, #0x50
	strh r0, [r1]
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ldrh r3, [r4, #0xa]
	adds r0, r0, r3
	adds r3, r5, #0
	adds r3, #0x52
	strh r0, [r3]
	ldrh r0, [r4, #0xc]
	adds r2, r5, #0
	adds r2, #0x54
	strh r0, [r2]
	ldrh r1, [r1]
	movs r4, #0x9e
	lsls r4, r4, #2
	adds r0, r6, r4
	strh r1, [r0]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	ldrh r3, [r3]
	adds r0, r0, r3
	ldr r3, _08024470 @ =0x0000027A
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r1, [r2]
	adds r4, #4
	adds r0, r6, r4
	strh r1, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	b _080244B4
	.align 2, 0
_08024470: .4byte 0x0000027A
_08024474:
	movs r1, #2
	movs r2, #0
	movs r3, #3
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
	b _080244CE
_0802448A:
	movs r1, #2
	movs r2, #0
	movs r3, #4
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
	b _080244CE
_080244A0:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0xb4
	movs r3, #0xb4
	bl FUN_080230d8
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r0, r5, r3
_080244B4:
	movs r1, #1
	bl FUN_08022488
	b _080244DA
_080244BC:
	movs r1, #2
	movs r2, #0
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
_080244CE:
	adds r0, #0x16
	str r2, [r0]
_080244D2:
	adds r1, r5, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
_080244DA:
	adds r7, #1
	ldr r0, _080244FC @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, r8
	adds r0, #6
_080244E6:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _080244F2
	b _08024378
_080244F2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080244FC: .4byte 0x03002B4C

	thumb_func_start FUN_08024500
FUN_08024500: @ 0x08024500
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r6, #0
	adds r7, #0x48
	bl FUN_08024350
	adds r0, r7, #0
	bl FUN_0823b4b8
	adds r0, r6, #0
	bl FUN_08023d7c
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	adds r0, r6, #0
	bl FUN_08022dfc
	adds r0, r6, #0
	bl FUN_08023388
	movs r2, #0xac
	lsls r2, r2, #1
	adds r1, r6, r2
	subs r2, #0x58
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r7, #0xa]
	ldrh r1, [r7, #8]
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	ldrh r2, [r7, #0xa]
	adds r0, r0, r2
	ldr r2, _080245DC @ =0x0000027A
	adds r1, r6, r2
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	adds r0, r6, #0
	bl FUN_08022e20
	movs r0, #0x86
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r8, r0
	ldr r1, [r0]
	cmp r1, #0
	beq _080245AC
	movs r2, #0
	ldrsh r5, [r1, r2]
	movs r2, #8
	ldrsh r0, [r7, r2]
	subs r5, r5, r0
	movs r0, #4
	ldrsh r4, [r1, r0]
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r1, r6, #0
	adds r1, #0xc8
	strb r0, [r1]
	adds r2, r6, #0
	adds r2, #0xc0
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_080245AC:
	adds r0, r6, #0
	bl FUN_08023b10
	adds r0, r6, #0
	adds r0, #0x50
	bl FUN_080234ec
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	bl FUN_080234ec
	ldr r2, _080245E0 @ =0x00000165
	adds r1, r6, r2
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080245DC: .4byte 0x0000027A
_080245E0: .4byte 0x00000165

	thumb_func_start FUN_080245e4
FUN_080245e4: @ 0x080245E4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r4, r6, #0
	adds r4, #0x48
	bl FUN_08022ec0
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _08024610
	movs r2, #4
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
_08024610:
	movs r2, #0xa
	ldrsh r1, [r4, r2]
	ldr r0, _08024640 @ =0x0000027F
	adds r7, r6, #0
	adds r7, #0x98
	cmp r1, r0
	ble _08024626
	movs r1, #4
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
_08024626:
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r4, r6, r3
	movs r1, #4
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _08024644
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	b _0802465C
	.align 2, 0
_08024640: .4byte 0x0000027F
_08024644:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
_0802465C:
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r4, r5, r1
	movs r1, #8
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _08024676
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	b _08024694
_08024676:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_08024694:
	ldr r0, _080246D8 @ =0x0000054A
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _0802473C
	ldr r2, _080246DC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080246E0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080246E4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r2, _080246E8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov ip, r0
	ldrb r0, [r3]
	lsls r0, r0, #1
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _080246EC
	asrs r3, r0, #0xc
	b _080246F2
	.align 2, 0
_080246D8: .4byte 0x0000054A
_080246DC: .4byte 0x030046B8
_080246E0: .4byte 0x000003FF
_080246E4: .4byte 0x0203B400
_080246E8: .4byte 0x085B0A08
_080246EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080246F2:
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0802471C @ =0x0000054A
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _08024720
	asrs r2, r0, #0xc
	b _08024726
	.align 2, 0
_0802471C: .4byte 0x0000054A
_08024720:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08024726:
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r2, _08024758 @ =0x0000054A
	adds r1, r5, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0802473C:
	movs r1, #0x10
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _0802475C
	movs r3, #0x96
	lsls r3, r3, #2
	adds r2, r5, r3
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	b _08024778
	.align 2, 0
_08024758: .4byte 0x0000054A
_0802475C:
	movs r3, #0x96
	lsls r3, r3, #2
	adds r2, r5, r3
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _08024788
_08024778:
	ldr r1, _08024784 @ =0x000004D4
	adds r0, r5, r1
	bl FUN_080139a0
	b _08024790
	.align 2, 0
_08024784: .4byte 0x000004D4
_08024788:
	ldr r2, _080247C8 @ =0x000004D4
	adds r0, r5, r2
	bl FUN_08013984
_08024790:
	movs r3, #0xa9
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _080247D8
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	adds r2, r6, #0
	adds r2, #0xe0
	cmp r0, #0
	bne _080247DC
	ldr r0, _080247CC @ =0x00000292
	adds r1, r5, r0
	subs r0, #0x6f
	strh r0, [r1]
	movs r3, #0xa8
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r0, _080247D0 @ =0x03003584
	ldr r0, [r0]
	ldr r3, _080247D4 @ =0x00004460
	adds r0, r0, r3
	str r0, [r1]
	b _080247DC
	.align 2, 0
_080247C8: .4byte 0x000004D4
_080247CC: .4byte 0x00000292
_080247D0: .4byte 0x03003584
_080247D4: .4byte 0x00004460
_080247D8:
	adds r2, r6, #0
	adds r2, #0xe0
_080247DC:
	ldr r0, _08024800 @ =0x00000564
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb4
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024800: .4byte 0x00000564

	thumb_func_start FUN_08024804
FUN_08024804: @ 0x08024804
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08009154
	cmp r0, #0
	bne _08024814
	movs r0, #0
	b _0802482C
_08024814:
	movs r0, #5
	adds r2, r4, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
_0802482C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08024834
FUN_08024834: @ 0x08024834
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r7, #0
	bl FUN_08009154
	adds r2, r0, #0
	cmp r2, #0
	bne _08024850
	b _080249C6
_08024850:
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xa3
	bls _0802485E
	b _080249B0
_0802485E:
	adds r2, r7, #0
	adds r2, #0x48
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xa3
	bhi _0802489E
	movs r3, #8
	ldrsh r0, [r2, r3]
	movs r3, #0xee
	lsls r3, r3, #3
	adds r1, r7, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	cmp r0, #0
	bge _08024880
	rsbs r0, r0, #0
_08024880:
	cmp r0, #0x3f
	bgt _0802489E
	movs r1, #0xc
	ldrsh r0, [r2, r1]
	ldr r2, _080248CC @ =0x00000774
	adds r1, r7, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	cmp r0, #0
	bge _08024898
	rsbs r0, r0, #0
_08024898:
	movs r1, #1
	cmp r0, #0x3f
	ble _080248A0
_0802489E:
	movs r1, #0
_080248A0:
	cmp r1, #0
	beq _080248EE
	ldr r1, _080248D0 @ =0x00000553
	adds r0, r7, r1
	ldr r2, _080248D4 @ =0x0000077C
	adds r1, r7, r2
	ldrb r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080248D8
	movs r0, #7
	adds r2, r4, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	b _08024B5C
	.align 2, 0
_080248CC: .4byte 0x00000774
_080248D0: .4byte 0x00000553
_080248D4: .4byte 0x0000077C
_080248D8:
	movs r0, #6
	adds r2, r4, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	b _08024B5C
_080248EE:
	movs r3, #0xee
	lsls r3, r3, #3
	adds r2, r7, r3
	mov sl, r7
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _08024904 @ =0x0000011F
	cmp r1, r0
	bgt _08024908
	adds r0, #1
	b _08024910
	.align 2, 0
_08024904: .4byte 0x0000011F
_08024908:
	movs r0, #0xbe
	lsls r0, r0, #4
	cmp r1, r0
	ble _08024912
_08024910:
	strh r0, [r2]
_08024912:
	movs r3, #4
	ldrsh r1, [r2, r3]
	ldr r0, _08024920 @ =0x0000021F
	cmp r1, r0
	bgt _08024924
	adds r0, #1
	b _0802492C
	.align 2, 0
_08024920: .4byte 0x0000021F
_08024924:
	movs r0, #0xce
	lsls r0, r0, #4
	cmp r1, r0
	ble _0802492E
_0802492C:
	strh r0, [r2, #4]
_0802492E:
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r4, [r2, r3]
	adds r3, r7, #0
	adds r3, #0xcc
	movs r6, #0
	strh r0, [r3]
	adds r0, r7, #0
	adds r0, #0xce
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0xd0
	strh r4, [r2]
	movs r0, #0xdc
	adds r0, r0, r7
	mov r8, r0
	strb r6, [r0]
	adds r1, r7, #0
	adds r1, #0x48
	movs r0, #0
	ldrsh r5, [r3, r0]
	movs r3, #8
	ldrsh r0, [r1, r3]
	subs r5, r5, r0
	movs r0, #0
	ldrsh r4, [r2, r0]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r1, r7, #0
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	adds r2, r7, #0
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #1
	mov r3, r8
	strb r1, [r3]
	mov r0, sl
	adds r0, #0xa4
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	movs r2, #0
	str r2, [r0]
	subs r0, #0x14
	strb r1, [r0]
	b _08024B60
_080249B0:
	movs r0, #5
	adds r2, r7, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa8
	b _08024B5C
_080249C6:
	ldr r3, _080249DC @ =0x0000054C
	adds r0, r7, r3
	ldrb r3, [r0]
	cmp r3, #0
	beq _080249E0
	movs r0, #2
	adds r1, r7, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r7, #0
	b _08024B56
	.align 2, 0
_080249DC: .4byte 0x0000054C
_080249E0:
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r0, _08024A24 @ =0x000002FF
	cmp r1, r0
	bls _080249F0
	b _08024B08
_080249F0:
	ldr r2, _08024A28 @ =0x00000165
	adds r0, r7, r2
	ldrb r1, [r0]
	adds r1, #2
	movs r0, #3
	ands r1, r0
	movs r2, #0xc0
	lsls r2, r2, #2
	mov r0, sp
	bl FUN_08023dc8
	mov r3, sp
	mov sb, r7
	mov sl, r7
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08024A2C @ =0x0000011F
	cmp r1, r0
	bgt _08024A30
	movs r1, #0x90
	lsls r1, r1, #1
	mov r0, sp
	strh r1, [r0]
	b _08024A3C
	.align 2, 0
_08024A24: .4byte 0x000002FF
_08024A28: .4byte 0x00000165
_08024A2C: .4byte 0x0000011F
_08024A30:
	movs r2, #0xbe
	lsls r2, r2, #4
	cmp r1, r2
	ble _08024A3C
	mov r0, sp
	strh r2, [r0]
_08024A3C:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldr r0, _08024A4C @ =0x0000021F
	cmp r1, r0
	bgt _08024A50
	adds r0, #1
	b _08024A58
	.align 2, 0
_08024A4C: .4byte 0x0000021F
_08024A50:
	movs r0, #0xce
	lsls r0, r0, #4
	cmp r1, r0
	ble _08024A5A
_08024A58:
	strh r0, [r3, #4]
_08024A5A:
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r2, #4
	ldrsh r4, [r3, r2]
	mov r3, sl
	adds r3, #0xcc
	movs r6, #0
	strh r0, [r3]
	mov r0, sl
	adds r0, #0xce
	strh r1, [r0]
	mov r2, sl
	adds r2, #0xd0
	strh r4, [r2]
	movs r0, #0xdc
	add r0, sl
	mov r8, r0
	strb r6, [r0]
	mov r1, sl
	adds r1, #0x48
	movs r0, #0
	ldrsh r5, [r3, r0]
	movs r3, #8
	ldrsh r0, [r1, r3]
	subs r5, r5, r0
	movs r0, #0
	ldrsh r4, [r2, r0]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	mov r1, sl
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	mov r2, sl
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #1
	mov r3, r8
	strb r1, [r3]
	mov r0, sb
	adds r0, #0xa4
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	movs r2, #0
	str r2, [r0]
	subs r0, #0x14
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x5f
	bgt _08024B60
	bl FUN_080591f4
	movs r1, #0
	cmp r0, #5
	bgt _08024AFA
	bl FUN_08059210
	movs r1, #4
	cmp r0, #0
	bne _08024AFA
	movs r1, #6
_08024AFA:
	ldr r3, _08024B04 @ =0x00000551
	adds r0, r7, r3
	strb r1, [r0]
	b _08024B60
	.align 2, 0
_08024B04: .4byte 0x00000551
_08024B08:
	adds r0, r7, #0
	adds r0, #0x9c
	ldrb r2, [r0]
	cmp r2, #0
	beq _08024B4C
	ldr r1, _08024B24 @ =0x00000554
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08024B28
	movs r0, #8
	b _08024B2A
	.align 2, 0
_08024B24: .4byte 0x00000554
_08024B28:
	movs r0, #2
_08024B2A:
	adds r1, r7, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xbc
	str r3, [r0]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	ldr r2, _08024B48 @ =0x00000554
	adds r1, r7, r2
	ldrb r0, [r1]
	adds r0, #1
	b _08024B5E
	.align 2, 0
_08024B48: .4byte 0x00000554
_08024B4C:
	movs r0, #2
	adds r1, r4, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r4, #0
_08024B56:
	adds r0, #0xbc
	str r2, [r0]
	adds r1, #2
_08024B5C:
	movs r0, #1
_08024B5E:
	strb r0, [r1]
_08024B60:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08024b70
FUN_08024b70: @ 0x08024B70
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08024804
	adds r2, r0, #0
	cmp r2, #0
	bne _08024BD8
	ldr r1, _08024B94 @ =0x00000173
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #1
	beq _08024B98
	cmp r3, #2
	beq _08024BBC
	adds r0, r4, #0
	bl FUN_08024834
	b _08024BD0
	.align 2, 0
_08024B94: .4byte 0x00000173
_08024B98:
	movs r1, #0x78
	adds r0, r4, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r3, [r0]
	ldr r2, _08024BB8 @ =0x0000055A
	adds r0, r4, r2
	strh r1, [r0]
	b _08024BD0
	.align 2, 0
_08024BB8: .4byte 0x0000055A
_08024BBC:
	movs r0, #3
	adds r1, r4, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	str r2, [r0]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
_08024BD0:
	ldr r0, _08024BE0 @ =0x00000173
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_08024BD8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08024BE0: .4byte 0x00000173

	thumb_func_start FUN_08024be4
FUN_08024be4: @ 0x08024BE4
	push {lr}
	adds r3, r0, #0
	movs r1, #2
	adds r0, #0x98
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _08024C10
	movs r1, #1
	movs r2, #0
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
	b _08024C32
_08024C10:
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	bne _08024C1C
	movs r0, #0
	b _08024C34
_08024C1C:
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
_08024C32:
	movs r0, #1
_08024C34:
	pop {r1}
	bx r1

	thumb_func_start FUN_08024c38
FUN_08024c38: @ 0x08024C38
	push {lr}
	adds r3, r0, #0
	mov ip, r3
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08024C54
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08024C5A
_08024C54:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_08024C5A:
	adds r2, r0, #0
	cmp r2, #1
	bne _08024C66
	adds r0, r3, #0
	adds r0, #0xa2
	strb r2, [r0]
_08024C66:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08024C74
	mov r0, ip
	bl FUN_08024834
	b _08024C7E
_08024C74:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08024C7E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08024c84
FUN_08024c84: @ 0x08024C84
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08024CA2
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	adds r4, r1, #0
	b _08024CA8
_08024CA2:
	movs r0, #0
	adds r4, r2, #0
	adds r4, #0xa7
_08024CA8:
	cmp r0, #0
	beq _08024CC8
	movs r0, #2
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x18
	ldr r5, _08024CD8 @ =0x0000055C
	adds r0, r3, r5
	strh r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #3
	adds r1, r3, r0
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r1]
_08024CC8:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08024CDC
	adds r0, r3, #0
	bl FUN_08024b70
	b _08024CE6
	.align 2, 0
_08024CD8: .4byte 0x0000055C
_08024CDC:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08024CE6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08024cec
FUN_08024cec: @ 0x08024CEC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	mov r2, r8
	mov r1, r8
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08024D10
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08024D16
_08024D10:
	movs r0, #0
	movs r1, #0xa7
	add r1, r8
_08024D16:
	mov sb, r1
	cmp r0, #0
	beq _08024D38
	movs r0, #2
	mov r1, r8
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x18
	ldr r3, _08024D64 @ =0x0000055C
	adds r0, r2, r3
	strh r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #3
	adds r1, r2, r0
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r1]
_08024D38:
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, sp
	ldr r3, _08024D68 @ =0xFFFFFE00
	adds r0, r3, #0
	ldrh r3, [r1, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
	ldr r3, _08024D6C @ =0x0000054C
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08024D70
	movs r0, #0x80
	b _08024D74
	.align 2, 0
_08024D64: .4byte 0x0000055C
_08024D68: .4byte 0xFFFFFE00
_08024D6C: .4byte 0x0000054C
_08024D70:
	movs r0, #0xc0
	lsls r0, r0, #2
_08024D74:
	strh r0, [r1, #2]
	mov r4, sp
	adds r7, r2, #0
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08024D90 @ =0x0000011F
	cmp r1, r0
	bgt _08024D94
	movs r1, #0x90
	lsls r1, r1, #1
	mov r0, sp
	strh r1, [r0]
	b _08024DA0
	.align 2, 0
_08024D90: .4byte 0x0000011F
_08024D94:
	movs r2, #0xbe
	lsls r2, r2, #4
	cmp r1, r2
	ble _08024DA0
	mov r0, sp
	strh r2, [r0]
_08024DA0:
	movs r3, #4
	ldrsh r1, [r4, r3]
	ldr r0, _08024DB0 @ =0x0000021F
	cmp r1, r0
	bgt _08024DB4
	adds r0, #1
	b _08024DBC
	.align 2, 0
_08024DB0: .4byte 0x0000021F
_08024DB4:
	movs r0, #0xce
	lsls r0, r0, #4
	cmp r1, r0
	ble _08024DBE
_08024DBC:
	strh r0, [r4, #4]
_08024DBE:
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #2
	ldrsh r1, [r4, r2]
	movs r3, #4
	ldrsh r4, [r4, r3]
	adds r3, r7, #0
	adds r3, #0xcc
	movs r5, #0
	strh r0, [r3]
	adds r0, r7, #0
	adds r0, #0xce
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0xd0
	strh r4, [r2]
	adds r6, r7, #0
	adds r6, #0xdc
	strb r5, [r6]
	adds r1, r7, #0
	adds r1, #0x48
	movs r0, #0
	ldrsh r5, [r3, r0]
	movs r3, #8
	ldrsh r0, [r1, r3]
	subs r5, r5, r0
	movs r0, #0
	ldrsh r4, [r2, r0]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r1, r7, #0
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	adds r2, r7, #0
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	movs r2, #1
	strb r2, [r6]
	mov r3, sb
	ldrb r0, [r3]
	cmp r0, #0
	beq _08024E40
	movs r0, #3
	mov r1, r8
	adds r1, #0xa6
	strb r0, [r1]
	adds r1, #0x16
	movs r0, #0
	str r0, [r1]
	mov r0, r8
	adds r0, #0xa8
	strb r2, [r0]
	b _08024E4A
_08024E40:
	mov r1, r8
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08024E4A:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08024e58
FUN_08024e58: @ 0x08024E58
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov r8, sb
	mov r1, sb
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08024E7E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08024E84
_08024E7E:
	movs r0, #0
	mov r1, sb
	adds r1, #0xa7
_08024E84:
	str r1, [sp, #8]
	cmp r0, #0
	beq _08024EA6
	movs r0, #3
	mov r1, sb
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x18
	ldr r0, _08024ED0 @ =0x0000055C
	add r0, r8
	strh r1, [r0]
	movs r1, #0xac
	lsls r1, r1, #3
	add r1, r8
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r1]
_08024EA6:
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, sp
	ldr r2, _08024ED4 @ =0xFFFFFE00
	adds r0, r2, #0
	ldrh r3, [r1, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
	ldr r0, _08024ED8 @ =0x0000054C
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08024EDC
	movs r0, #0x80
	b _08024EE0
	.align 2, 0
_08024ED0: .4byte 0x0000055C
_08024ED4: .4byte 0xFFFFFE00
_08024ED8: .4byte 0x0000054C
_08024EDC:
	movs r0, #0xc0
	lsls r0, r0, #2
_08024EE0:
	strh r0, [r1, #2]
	mov r2, sp
	mov r7, r8
	mov r0, sp
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, _08024EFC @ =0x0000011F
	cmp r1, r0
	bgt _08024F00
	movs r1, #0x90
	lsls r1, r1, #1
	mov r0, sp
	strh r1, [r0]
	b _08024F0C
	.align 2, 0
_08024EFC: .4byte 0x0000011F
_08024F00:
	movs r3, #0xbe
	lsls r3, r3, #4
	cmp r1, r3
	ble _08024F0C
	mov r0, sp
	strh r3, [r0]
_08024F0C:
	movs r0, #4
	ldrsh r1, [r2, r0]
	ldr r0, _08024F1C @ =0x0000021F
	cmp r1, r0
	bgt _08024F20
	adds r0, #1
	b _08024F28
	.align 2, 0
_08024F1C: .4byte 0x0000021F
_08024F20:
	movs r0, #0xce
	lsls r0, r0, #4
	cmp r1, r0
	ble _08024F2A
_08024F28:
	strh r0, [r2, #4]
_08024F2A:
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r4, [r2, r3]
	adds r3, r7, #0
	adds r3, #0xcc
	movs r2, #0
	mov sl, r2
	strh r0, [r3]
	adds r0, r7, #0
	adds r0, #0xce
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0xd0
	strh r4, [r2]
	adds r6, r7, #0
	adds r6, #0xdc
	mov r0, sl
	strb r0, [r6]
	adds r1, r7, #0
	adds r1, #0x48
	movs r0, #0
	ldrsh r5, [r3, r0]
	movs r3, #8
	ldrsh r0, [r1, r3]
	subs r5, r5, r0
	movs r0, #0
	ldrsh r4, [r2, r0]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r1, r7, #0
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	adds r2, r7, #0
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	movs r3, #1
	strb r3, [r6]
	ldr r1, [sp, #8]
	ldrb r0, [r1]
	cmp r0, #0
	beq _08024FC8
	movs r2, #0x10
	mov r0, r8
	adds r0, #0xa4
	mov r1, sl
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	mov r1, r8
	adds r1, #0xbc
	movs r0, #0
	str r0, [r1]
	mov r0, r8
	adds r0, #0xa8
	strb r3, [r0]
	ldr r0, _08024FC4 @ =0x0000055A
	add r0, r8
	strh r2, [r0]
	b _08024FD2
	.align 2, 0
_08024FC4: .4byte 0x0000055A
_08024FC8:
	mov r1, sb
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08024FD2:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08024fe4
FUN_08024fe4: @ 0x08024FE4
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025002
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	adds r4, r1, #0
	b _08025008
_08025002:
	movs r0, #0
	adds r4, r2, #0
	adds r4, #0xa7
_08025008:
	cmp r0, #0
	beq _08025028
	movs r0, #6
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x18
	ldr r5, _08025054 @ =0x0000055C
	adds r0, r3, r5
	strh r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #3
	adds r1, r3, r0
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r1]
_08025028:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802505C
	movs r2, #0x5a
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
	ldr r1, _08025058 @ =0x0000055A
	adds r0, r3, r1
	strh r2, [r0]
	b _08025066
	.align 2, 0
_08025054: .4byte 0x0000055C
_08025058: .4byte 0x0000055A
_0802505C:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08025066:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802506c
FUN_0802506c: @ 0x0802506C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	mov sb, r7
	adds r1, r7, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025090
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08025096
_08025090:
	movs r0, #0
	movs r1, #0xa7
	adds r1, r1, r7
_08025096:
	mov r8, r1
	mov sl, r0
	cmp r0, #1
	bne _0802512C
	movs r0, #9
	adds r1, r7, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r0, #0xee
	lsls r0, r0, #3
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r4, #4
	ldrsh r3, [r0, r4]
	adds r0, r7, #0
	adds r0, #0xcc
	strh r1, [r0]
	adds r1, r7, #0
	adds r1, #0xce
	strh r2, [r1]
	adds r2, r7, #0
	adds r2, #0xd0
	strh r3, [r2]
	adds r6, r7, #0
	adds r6, #0xdc
	movs r1, #0
	strb r1, [r6]
	adds r1, r7, #0
	adds r1, #0x48
	movs r3, #0
	ldrsh r5, [r0, r3]
	movs r4, #8
	ldrsh r0, [r1, r4]
	subs r5, r5, r0
	movs r0, #0
	ldrsh r4, [r2, r0]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r1, r7, #0
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	adds r2, r7, #0
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	mov r3, sl
	strb r3, [r6]
	movs r1, #0x18
	ldr r0, _08025150 @ =0x0000055C
	add r0, sb
	strh r1, [r0]
	movs r1, #0xac
	lsls r1, r1, #3
	add r1, sb
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r1]
	ldr r0, _08025154 @ =0x00000553
	add r0, sb
	movs r4, #0
	strb r4, [r0]
_0802512C:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025158
	movs r0, #6
	adds r2, r7, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _08025162
	.align 2, 0
_08025150: .4byte 0x0000055C
_08025154: .4byte 0x00000553
_08025158:
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08025162:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08025170
FUN_08025170: @ 0x08025170
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802518E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	adds r4, r1, #0
	b _08025194
_0802518E:
	movs r0, #0
	adds r4, r2, #0
	adds r4, #0xa7
_08025194:
	cmp r0, #0
	beq _080251AA
	movs r0, #0xa
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
	ldr r0, _080251D8 @ =0x00000553
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080251AA:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080251E0
	movs r2, #0xf0
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
	ldr r1, _080251DC @ =0x0000055A
	adds r0, r3, r1
	strh r2, [r0]
	b _080251EA
	.align 2, 0
_080251D8: .4byte 0x00000553
_080251DC: .4byte 0x0000055A
_080251E0:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080251EA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080251f0
FUN_080251f0: @ 0x080251F0
	push {lr}
	adds r3, r0, #0
	mov ip, r3
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802520C
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08025212
_0802520C:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_08025212:
	cmp r0, #0
	beq _0802521E
	movs r0, #0xc
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802521E:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802522C
	mov r0, ip
	bl FUN_08024834
	b _08025236
_0802522C:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08025236:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802523c
FUN_0802523c: @ 0x0802523C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	mov r8, r7
	adds r1, r7, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025262
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08025268
_08025262:
	movs r0, #0
	movs r1, #0xa7
	adds r1, r1, r7
_08025268:
	mov sl, r1
	mov sb, r0
	cmp r0, #1
	bne _08025304
	movs r0, #0xd
	adds r1, r7, #0
	adds r1, #0xa2
	strb r0, [r1]
	mov r4, sp
	ldr r0, _08025328 @ =0x00000165
	add r0, r8
	ldrb r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
	mov r0, sp
	bl FUN_08023dc8
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #2
	ldrsh r1, [r4, r3]
	movs r2, #4
	ldrsh r4, [r4, r2]
	adds r3, r7, #0
	adds r3, #0xcc
	movs r5, #0
	strh r0, [r3]
	adds r0, r7, #0
	adds r0, #0xce
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0xd0
	strh r4, [r2]
	adds r6, r7, #0
	adds r6, #0xdc
	strb r5, [r6]
	adds r1, r7, #0
	adds r1, #0x48
	movs r0, #0
	ldrsh r5, [r3, r0]
	movs r3, #8
	ldrsh r0, [r1, r3]
	subs r5, r5, r0
	movs r0, #0
	ldrsh r4, [r2, r0]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r1, r7, #0
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	adds r2, r7, #0
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	mov r3, sb
	strb r3, [r6]
	movs r1, #0x20
	ldr r0, _0802532C @ =0x0000055C
	add r0, r8
	strh r1, [r0]
	movs r1, #0xac
	lsls r1, r1, #3
	add r1, r8
	movs r0, #0xa2
	lsls r0, r0, #3
	str r0, [r1]
_08025304:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025330
	movs r0, #4
	adds r2, r7, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0802533A
	.align 2, 0
_08025328: .4byte 0x00000165
_0802532C: .4byte 0x0000055C
_08025330:
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802533A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802534c
FUN_0802534c: @ 0x0802534C
	push {r4, lr}
	adds r3, r0, #0
	mov ip, r3
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025368
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802536A
_08025368:
	movs r0, #0
_0802536A:
	cmp r0, #0
	beq _08025376
	movs r0, #0xe
	adds r1, r3, #0
	adds r1, #0xa2
	strb r0, [r1]
_08025376:
	movs r4, #1
	adds r0, r3, #0
	adds r0, #0x98
	ldr r2, [r0]
	ands r2, r4
	cmp r2, #0
	bne _080253A8
	movs r1, #0xa
	mov r0, ip
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r4, [r0]
	ldr r0, _080253A4 @ =0x0000055A
	add r0, ip
	strh r1, [r0]
	b _080253B2
	.align 2, 0
_080253A4: .4byte 0x0000055A
_080253A8:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080253B2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080253b8
FUN_080253b8: @ 0x080253B8
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _080253CE
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
_080253CE:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0

	thumb_func_start FUN_080253dc
FUN_080253dc: @ 0x080253DC
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _080253F6
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _080253F8
_080253F6:
	movs r0, #0
_080253F8:
	cmp r0, #0
	beq _08025404
	movs r0, #0x12
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_08025404:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08025414
FUN_08025414: @ 0x08025414
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802542E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08025430
_0802542E:
	movs r0, #0
_08025430:
	cmp r0, #0
	beq _08025448
	movs r0, #0x13
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_08025448:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08025458
FUN_08025458: @ 0x08025458
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025472
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08025474
_08025472:
	movs r0, #0
_08025474:
	cmp r0, #0
	beq _0802548C
	movs r0, #0x14
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_0802548C:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802549c
FUN_0802549c: @ 0x0802549C
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _080254B6
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _080254BC
_080254B6:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_080254BC:
	cmp r0, #0
	beq _080254C8
	movs r0, #0x15
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_080254C8:
	ldrb r0, [r1]
	cmp r0, #0
	beq _080254F4
	movs r0, #2
	adds r2, r3, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _080254FE
_080254F4:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080254FE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08025504
FUN_08025504: @ 0x08025504
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802551E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08025524
_0802551E:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_08025524:
	cmp r0, #0
	beq _08025530
	movs r0, #0x16
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_08025530:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025558
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa6
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _08025562
_08025558:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08025562:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08025568
FUN_08025568: @ 0x08025568
	push {lr}
	ldr r2, _08025580 @ =0x085AAB08
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
_08025580: .4byte 0x085AAB08

	thumb_func_start FUN_08025584
FUN_08025584: @ 0x08025584
	push {lr}
	ldr r2, _0802559C @ =0x085AAB2C
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
_0802559C: .4byte 0x085AAB2C

	thumb_func_start FUN_080255a0
FUN_080255a0: @ 0x080255A0
	push {lr}
	ldr r2, _080255B8 @ =0x085AAB34
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
_080255B8: .4byte 0x085AAB34

	thumb_func_start FUN_080255bc
FUN_080255bc: @ 0x080255BC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #4
	ldr r0, _080255F0 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080255EA
	adds r0, r4, #0
	bl FUN_08024be4
	cmp r0, #0
	bne _080255EA
	ldr r0, _080255F4 @ =0x085AAB48
	adds r1, r4, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_080255EA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080255F0: .4byte 0x03002BC0
_080255F4: .4byte 0x085AAB48

	thumb_func_start FUN_080255f8
FUN_080255f8: @ 0x080255F8
	push {lr}
	ldr r2, _08025610 @ =0x085AAB4C
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
_08025610: .4byte 0x085AAB4C

	thumb_func_start FUN_08025614
FUN_08025614: @ 0x08025614
	push {lr}
	ldr r2, _0802562C @ =0x085AAB50
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
_0802562C: .4byte 0x085AAB50

	thumb_func_start FUN_08025630
FUN_08025630: @ 0x08025630
	push {lr}
	adds r2, r0, #0
	adds r2, #0x9d
	movs r1, #0
	strb r1, [r2]
	ldr r2, _08025650 @ =0x085AAB54
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
_08025650: .4byte 0x085AAB54

	thumb_func_start FUN_08025654
FUN_08025654: @ 0x08025654
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025680
	movs r3, #0
	strb r3, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	bl FUN_08022da8
_08025680:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080256B8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080256B8
	ldr r1, _080256C0 @ =0x0000055A
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r5, r0
	blt _080256B8
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080256B8:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080256C0: .4byte 0x0000055A

	thumb_func_start FUN_080256c4
FUN_080256c4: @ 0x080256C4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov sb, r1
	mov r8, r5
	adds r7, r5, #0
	adds r7, #0xcc
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025710
	movs r4, #0
	strb r4, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r0, #1
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_08022da8
	ldr r0, _08025764 @ =0x00000551
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r3, #0xaa
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	strb r4, [r2]
_08025710:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08025724
	b _08025820
_08025724:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025820
	adds r0, r5, #0
	adds r0, #0xd4
	ldr r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	movs r2, #0
	cmp r1, r0
	bhi _0802574E
	movs r2, #1
_0802574E:
	cmp r2, #0
	beq _08025768
	ldrh r1, [r7]
	adds r0, r5, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrh r1, [r7, #4]
	adds r0, #4
	strh r1, [r0]
	movs r4, #1
	b _080257C8
	.align 2, 0
_08025764: .4byte 0x00000551
_08025768:
	adds r0, r5, #0
	adds r0, #0xd8
	ldr r3, _08025794 @ =0x0000055C
	adds r1, r5, r3
	adds r4, r5, #0
	adds r4, #0x58
	ldr r3, [r0]
	ldrh r6, [r1]
	ldr r2, _08025798 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802579C
	asrs r1, r0, #0xc
	b _080257A2
	.align 2, 0
_08025794: .4byte 0x0000055C
_08025798: .4byte 0x085B0A08
_0802579C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080257A2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _080257BE
	asrs r0, r0, #0xc
	b _080257C4
_080257BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080257C4:
	strh r0, [r4, #4]
	movs r4, #0
_080257C8:
	movs r0, #7
	mov r3, sb
	ands r0, r3
	cmp r0, #0
	bne _080257E4
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0xff
	bls _080257E4
	mov r0, r8
	bl FUN_08023de8
_080257E4:
	movs r1, #2
	ldrsh r0, [r7, r1]
	movs r3, #0xac
	lsls r3, r3, #1
	add r3, r8
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r2, r0, #0
	cmp r0, #0
	bge _080257FA
	rsbs r2, r0, #0
_080257FA:
	cmp r2, #0x1f
	bgt _08025810
	ldrh r0, [r7, #2]
	strh r0, [r3]
	cmp r4, #0
	beq _08025820
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _08025820
_08025810:
	cmp r0, #0
	bge _0802581A
	adds r0, r1, #0
	subs r0, #0x20
	b _0802581E
_0802581A:
	adds r0, r1, #0
	adds r0, #0x20
_0802581E:
	strh r0, [r3]
_08025820:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08025830
FUN_08025830: @ 0x08025830
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802585E
	movs r3, #0
	strb r3, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_08022da8
_0802585E:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025936
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025936
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	movs r2, #0
	cmp r1, r0
	bhi _0802589A
	movs r2, #1
_0802589A:
	cmp r2, #0
	beq _080258AC
	adds r0, r4, #0
	adds r0, #0xcc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x50]
	str r1, [r4, #0x54]
	b _0802590A
_080258AC:
	adds r0, r4, #0
	adds r0, #0xd8
	ldr r2, _080258D8 @ =0x0000055C
	adds r1, r4, r2
	adds r5, r4, #0
	adds r5, #0x58
	ldr r3, [r0]
	ldrh r6, [r1]
	ldr r2, _080258DC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _080258E0
	asrs r1, r0, #0xc
	b _080258E6
	.align 2, 0
_080258D8: .4byte 0x0000055C
_080258DC: .4byte 0x085B0A08
_080258E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080258E6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08025902
	asrs r0, r0, #0xc
	b _08025908
_08025902:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08025908:
	strh r0, [r5, #4]
_0802590A:
	ldr r1, _08025940 @ =0x00000275
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08025936
	ldr r2, _08025944 @ =FUN_08025948
	movs r0, #4
	adds r3, r4, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_08025936:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08025940: .4byte 0x00000275
_08025944: .4byte FUN_08025948

	thumb_func_start FUN_08025948
FUN_08025948: @ 0x08025948
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r5, r0, #0
	mov r8, r1
	adds r7, r5, #0
	adds r6, r5, #0
	adds r6, #0x48
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080259CC
	movs r4, #0
	strb r4, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r0, #1
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r3, #2
	bl FUN_08022da8
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	ldr r2, _08025A7C @ =0x00000171
	adds r0, r5, r2
	strb r1, [r0]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _08025A80 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08025A84 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08025A88 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x38
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _08025A8C @ =0x000003B6
	bl PlaySound_0824078c
_080259CC:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080259E0
	b _08025C5E
_080259E0:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080259F6
	b _08025C5E
_080259F6:
	movs r3, #7
	mov r0, r8
	ands r3, r0
	cmp r3, #0
	bne _08025A58
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldr r2, _08025A80 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08025A84 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08025A88 @ =0x0203B400
	adds r0, r0, r1
	add r1, sp, #0x1c
	ldrh r1, [r1]
	subs r1, #0x80
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08025A90 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r2, _08025A94 @ =0x00003001
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	movs r0, #8
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	subs r0, #6
	str r0, [sp, #0x10]
	str r3, [sp, #0x14]
	add r3, sp, #0x1c
	str r3, [sp, #0x18]
	movs r0, #1
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015ce0
_08025A58:
	mov r0, r8
	cmp r0, #0x40
	ble _08025A60
	b _08025C2C
_08025A60:
	ldr r2, _08025A98 @ =0x085B0A08
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	mov ip, r2
	cmp r0, #0
	blt _08025A9C
	asrs r0, r0, #0xc
	b _08025AA2
	.align 2, 0
_08025A7C: .4byte 0x00000171
_08025A80: .4byte 0x030046B8
_08025A84: .4byte 0x000003FF
_08025A88: .4byte 0x0203B400
_08025A8C: .4byte 0x000003B6
_08025A90: .4byte 0xFFFF0000
_08025A94: .4byte 0x00003001
_08025A98: .4byte 0x085B0A08
_08025A9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08025AA2:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x24]
	mov r2, r8
	lsls r0, r2, #3
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08025AC2
	asrs r0, r0, #0xc
	b _08025AC8
_08025AC2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08025AC8:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08025B50 @ =0xFFFF0000
	add r3, sp, #0x24
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	adds r4, r6, #0
	adds r4, #8
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldrh r0, [r2]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r6, #8]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	mov r2, r8
	subs r2, #0x10
	cmp r2, #0x20
	bls _08025B04
	b _08025C2C
_08025B04:
	ldr r3, _08025B54 @ =0x00000171
	adds r1, r7, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08025B18
	b _08025C2C
_08025B18:
	ldr r3, _08025B58 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _08025B5C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08025B60 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r1, r2, #5
	movs r2, #0x3f
	ands r0, r2
	adds r1, r1, r0
	subs r1, #0xc8
	add r4, sp, #0x2c
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	adds r6, r3, #0
	mov sb, r4
	cmp r0, #0
	blt _08025B64
	asrs r2, r0, #0xc
	b _08025B6A
	.align 2, 0
_08025B50: .4byte 0xFFFF0000
_08025B54: .4byte 0x00000171
_08025B58: .4byte 0x030046B8
_08025B5C: .4byte 0x000003FF
_08025B60: .4byte 0x0203B400
_08025B64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08025B6A:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	movs r0, #0x40
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08025B84
	asrs r0, r0, #0xc
	b _08025B8A
_08025B84:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08025B8A:
	strh r0, [r4, #4]
	ldr r0, [r6]
	adds r0, #1
	ldr r4, _08025BE4 @ =0x000003FF
	ands r0, r4
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _08025BE8 @ =0x0203B400
	adds r0, r0, r1
	mov r2, sb
	ldrh r1, [r2]
	subs r1, #0x80
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrb r0, [r0]
	ldrh r2, [r2]
	mov ip, r2
	add r0, ip
	adds r1, r1, r0
	add r2, sp, #0x2c
	strh r1, [r2]
	movs r0, #0xbe
	lsls r0, r0, #1
	ldrh r0, [r0, r7]
	ldrh r3, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r2, #2]
	mov r0, ip
	lsls r3, r0, #0x10
	lsls r1, r1, #0x10
	cmp r3, r1
	blt _08025BEC
	ldr r0, [r6]
	adds r0, #1
	ands r0, r4
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _08025BE8 @ =0x0203B400
	adds r0, r0, r1
	b _08025BFA
	.align 2, 0
_08025BE4: .4byte 0x000003FF
_08025BE8: .4byte 0x0203B400
_08025BEC:
	ldr r0, [r6]
	adds r0, #1
	ands r0, r4
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08025C70 @ =0x0203B400
	adds r0, r0, r2
_08025BFA:
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r1, r0, #0
	adds r1, #0x40
	movs r4, #0
	str r4, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	ldr r3, _08025C74 @ =0x0000078A
	adds r0, r7, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	mov r3, sb
	str r3, [sp, #0x10]
	movs r0, #1
	movs r2, #0
	movs r3, #2
	bl FUN_08056774
	ldr r1, _08025C78 @ =0x00000171
	adds r0, r7, r1
	strb r4, [r0]
_08025C2C:
	mov r2, r8
	cmp r2, #0x3f
	ble _08025C5E
	ldr r3, _08025C7C @ =0x00000275
	adds r0, r7, r3
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08025C5E
	ldr r2, _08025C80 @ =FUN_08025c84
	movs r0, #5
	adds r3, r5, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_08025C5E:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08025C70: .4byte 0x0203B400
_08025C74: .4byte 0x0000078A
_08025C78: .4byte 0x00000171
_08025C7C: .4byte 0x00000275
_08025C80: .4byte FUN_08025c84

	thumb_func_start FUN_08025c84
FUN_08025c84: @ 0x08025C84
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025CB0
	movs r3, #0
	strb r3, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	movs r3, #3
	bl FUN_08022da8
_08025CB0:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025CEC
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025CEC
	ldr r1, _08025CF4 @ =0x00000275
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08025CEC
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08025CEC:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08025CF4: .4byte 0x00000275

	thumb_func_start FUN_08025cf8
FUN_08025cf8: @ 0x08025CF8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r4, #0
	adds r6, r4, #0
	adds r6, #0x48
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025D32
	movs r3, #0
	strb r3, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	bl FUN_08022da8
_08025D32:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025E02
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025E02
	movs r3, #0x9f
	lsls r3, r3, #2
	adds r2, r4, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r3, #4
	ldrsh r0, [r5, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _08025D6E
	rsbs r1, r1, #0
_08025D6E:
	cmp r1, #0x20
	ble _08025D8A
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	movs r3, #0x20
	rsbs r3, r3, #0
	adds r2, r3, #0
	cmp r1, r0
	bge _08025D86
	movs r2, #0x20
_08025D86:
	strh r2, [r6, #0x14]
	b _08025D92
_08025D8A:
	ldrh r0, [r5, #4]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r6, #0x14]
_08025D92:
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r3, #0
	ldrsh r0, [r5, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _08025DA8
	rsbs r1, r1, #0
_08025DA8:
	cmp r1, #0x20
	ble _08025DC4
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r3, #0x20
	rsbs r3, r3, #0
	adds r2, r3, #0
	cmp r1, r0
	bge _08025DC0
	movs r2, #0x20
_08025DC0:
	strh r2, [r6, #0x10]
	b _08025DCC
_08025DC4:
	ldrh r0, [r5]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r6, #0x10]
_08025DCC:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	movs r3, #0xc8
	lsls r3, r3, #5
	cmp r0, r3
	bhi _08025DE2
	adds r0, #0x40
	strh r0, [r1]
	b _08025E02
_08025DE2:
	movs r2, #0
	strh r3, [r1]
	ldr r1, _08025E0C @ =FUN_08025e10
	movs r0, #7
	adds r3, r4, #0
	adds r3, #0xa3
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_08025E02:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08025E0C: .4byte FUN_08025e10

	thumb_func_start FUN_08025e10
FUN_08025e10: @ 0x08025E10
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025E6E
	movs r3, #0
	strb r3, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	movs r3, #4
	bl FUN_08022da8
	ldr r2, _08025E9C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08025EA0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08025EA4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #3
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08024068
	movs r0, #0xee
	lsls r0, r0, #2
	bl PlaySound_0824078c
_08025E6E:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025E94
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08025EA8
_08025E94:
	adds r0, r4, #0
	bl FUN_080240b4
	b _08025F7E
	.align 2, 0
_08025E9C: .4byte 0x030046B8
_08025EA0: .4byte 0x000003FF
_08025EA4: .4byte 0x0203B400
_08025EA8:
	ldr r2, _08025EE8 @ =0x0000027A
	adds r0, r4, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08025EEC @ =0x00000FFF
	cmp r1, r0
	ble _08025F4A
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	movs r2, #0
	cmp r1, r0
	bhi _08025ED4
	movs r2, #1
_08025ED4:
	cmp r2, #0
	beq _08025EF0
	ldrh r1, [r3]
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrh r1, [r3, #4]
	adds r0, #4
	strh r1, [r0]
	b _08025F4A
	.align 2, 0
_08025EE8: .4byte 0x0000027A
_08025EEC: .4byte 0x00000FFF
_08025EF0:
	adds r0, r4, #0
	adds r0, #0xc8
	ldr r2, _08025F1C @ =0x0000055C
	adds r1, r4, r2
	adds r3, r4, #0
	adds r3, #0x58
	ldrb r5, [r0]
	ldrh r6, [r1]
	ldr r2, _08025F20 @ =0x085B0A08
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
	blt _08025F24
	asrs r1, r0, #0xc
	b _08025F2A
	.align 2, 0
_08025F1C: .4byte 0x0000055C
_08025F20: .4byte 0x085B0A08
_08025F24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08025F2A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08025F42
	asrs r0, r0, #0xc
	b _08025F48
_08025F42:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08025F48:
	strh r0, [r3, #4]
_08025F4A:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0x80
	bls _08025F5C
	subs r0, #0x80
	strh r0, [r1]
	b _08025F7E
_08025F5C:
	movs r2, #0
	movs r0, #0x80
	strh r0, [r1]
	ldr r1, _08025F88 @ =FUN_08025f8c
	movs r0, #8
	adds r3, r4, #0
	adds r3, #0xa3
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_08025F7E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08025F88: .4byte FUN_08025f8c

	thumb_func_start FUN_08025f8c
FUN_08025f8c: @ 0x08025F8C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025FFC
	movs r3, #0
	strb r3, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r7, #0
	movs r3, #5
	bl FUN_08022da8
	adds r6, r7, #0
	adds r6, #0x50
	ldr r1, _08026044 @ =0x00003001
	mov r8, r1
	movs r5, #0x40
	str r5, [sp]
	movs r0, #8
	str r0, [sp, #4]
	movs r4, #0x80
	lsls r4, r4, #1
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	movs r1, #4
	movs r2, #5
	mov r3, r8
	bl FUN_08015a90
	str r5, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	movs r1, #6
	movs r2, #5
	mov r3, r8
	bl FUN_08015a90
	adds r0, r7, #0
	bl FUN_080240b4
_08025FFC:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08026038
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08026038
	ldr r1, _08026048 @ =0x00000275
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08026038
	adds r1, r7, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08026038:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026044: .4byte 0x00003001
_08026048: .4byte 0x00000275

	thumb_func_start FUN_0802604c
FUN_0802604c: @ 0x0802604C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r4, #0
	movs r0, #0xcc
	adds r0, r0, r4
	mov r8, r0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08026090
	movs r3, #0
	strb r3, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r5, #0x8e
	lsls r5, r5, #2
	adds r2, r4, r5
	movs r0, #1
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	bl FUN_08022da8
	ldr r6, _08026114 @ =0x0000077A
	adds r0, r4, r6
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_08024004
_08026090:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080260A4
	b _080261A8
_080260A4:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080261A8
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r2, [r0]
	ldr r1, _08026118 @ =0x0003FFFF
	adds r5, r0, #0
	cmp r2, r1
	bhi _080260E8
	subs r0, #0x22
	ldrh r3, [r0]
	cmp r3, #0
	bne _080260E8
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r6, #0x8e
	lsls r6, r6, #2
	adds r2, r4, r6
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	movs r3, #6
	bl FUN_08022da8
_080260E8:
	ldr r0, [r5]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r1, [r1]
	movs r2, #0
	cmp r0, r1
	bhi _080260FA
	movs r2, #1
_080260FA:
	cmp r2, #0
	beq _0802611C
	adds r2, r4, #0
	adds r2, #0xcc
	ldrh r1, [r2]
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrh r1, [r2, #4]
	adds r0, #4
	strh r1, [r0]
	movs r3, #1
	b _0802617C
	.align 2, 0
_08026114: .4byte 0x0000077A
_08026118: .4byte 0x0003FFFF
_0802611C:
	adds r0, r4, #0
	adds r0, #0xd8
	ldr r5, _08026148 @ =0x0000055C
	adds r1, r7, r5
	adds r5, r4, #0
	adds r5, #0x58
	ldr r3, [r0]
	ldrh r6, [r1]
	ldr r2, _0802614C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08026150
	asrs r1, r0, #0xc
	b _08026156
	.align 2, 0
_08026148: .4byte 0x0000055C
_0802614C: .4byte 0x085B0A08
_08026150:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08026156:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08026172
	asrs r0, r0, #0xc
	b _08026178
_08026172:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08026178:
	strh r0, [r5, #4]
	movs r3, #0
_0802617C:
	movs r5, #0xac
	lsls r5, r5, #1
	adds r1, r7, r5
	ldrh r2, [r1]
	mov r6, r8
	movs r5, #2
	ldrsh r0, [r6, r5]
	cmp r2, r0
	ble _08026196
	adds r0, r2, #0
	subs r0, #0x10
	strh r0, [r1]
	b _080261A8
_08026196:
	mov r6, r8
	ldrh r0, [r6, #2]
	strh r0, [r1]
	cmp r3, #0
	beq _080261A8
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080261A8:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080261b4
FUN_080261b4: @ 0x080261B4
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r5, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080261FA
	movs r4, #0
	strb r4, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r3, #6
	bl FUN_08022da8
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _08026258 @ =0x000003B7
	bl PlaySound_0824078c
_080261FA:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080262B0
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080262B0
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _0802626C
	ldr r2, _0802625C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08026260 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08026264 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r1, r0
	ldr r2, _08026268 @ =0x0000056C
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08026254
	movs r2, #0x10
	bl FUN_08059a78
_08026254:
	movs r0, #0x18
	b _0802626E
	.align 2, 0
_08026258: .4byte 0x000003B7
_0802625C: .4byte 0x030046B8
_08026260: .4byte 0x000003FF
_08026264: .4byte 0x0203B400
_08026268: .4byte 0x0000056C
_0802626C:
	subs r0, #1
_0802626E:
	strb r0, [r4]
	ldr r1, _080262B8 @ =0x00000275
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080262B0
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080262B0
	ldr r1, _080262BC @ =FUN_080262c0
	movs r0, #0xb
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
_080262B0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080262B8: .4byte 0x00000275
_080262BC: .4byte FUN_080262c0

	thumb_func_start FUN_080262c0
FUN_080262c0: @ 0x080262C0
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080262EC
	movs r3, #0
	strb r3, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	movs r3, #7
	bl FUN_08022da8
_080262EC:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08026328
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08026328
	ldr r1, _08026330 @ =0x00000275
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08026328
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08026328:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08026330: .4byte 0x00000275

	thumb_func_start FUN_08026334
FUN_08026334: @ 0x08026334
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r5, r0, #0
	str r1, [sp, #0x24]
	adds r7, r5, #0
	movs r0, #0x48
	adds r0, r0, r5
	mov sl, r0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080263D0
	movs r3, #0
	strb r3, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r6, #0x8e
	lsls r6, r6, #2
	adds r2, r5, r6
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r5, #0
	movs r3, #9
	bl FUN_08022da8
	bl FUN_08009154
	cmp r0, #0
	beq _080263BA
	movs r4, #0
	ldr r0, _080264E8 @ =0x0203B400
	mov sb, r0
	ldr r3, _080264EC @ =0x030046B8
	movs r1, #0xad
	lsls r1, r1, #3
	adds r1, r5, r1
	str r1, [sp, #0x28]
	movs r2, #0x18
	ldr r6, _080264F0 @ =0x000003FF
	mov r8, r6
	movs r0, #3
	mov ip, r0
_08026396:
	ldr r0, [r3]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	ldr r6, [sp, #0x28]
	adds r1, r6, r4
	mov r6, ip
	ands r0, r6
	adds r0, r2, r0
	strb r0, [r1]
	adds r2, #3
	adds r4, #1
	cmp r4, #3
	ble _08026396
_080263BA:
	ldr r0, _080264F4 @ =0x0000054C
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xef
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl FUN_08024004
_080263D0:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080264D8
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080264D8
	adds r0, r5, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	cmp r0, #9
	bne _08026488
	movs r6, #0xac
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r2]
	ldr r0, _080264F8 @ =0x000002FF
	cmp r1, r0
	bhi _08026414
	adds r0, r1, #0
	adds r0, #0x10
	strh r0, [r2]
_08026414:
	ldr r0, _080264FC @ =0x0000FFFC
	mov r1, sl
	strh r0, [r1, #0x14]
	movs r3, #7
	ldr r2, [sp, #0x24]
	ands r3, r2
	cmp r3, #0
	bne _08026488
	ldr r0, [r1, #8]
	ldr r1, [r1, #0xc]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldr r2, _080264EC @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _080264F0 @ =0x000003FF
	ands r1, r0
	str r1, [r2]
	lsls r1, r1, #1
	ldr r6, _080264E8 @ =0x0203B400
	adds r1, r1, r6
	add r0, sp, #0x1c
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08026500 @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	subs r1, #0x40
	lsls r1, r1, #0x10
	ldr r0, _08026504 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r2, _08026508 @ =0x00003001
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	movs r0, #8
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	subs r0, #6
	str r0, [sp, #0x10]
	str r3, [sp, #0x14]
	add r0, sp, #0x1c
	str r0, [sp, #0x18]
	movs r0, #1
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015ce0
_08026488:
	movs r4, #0
_0802648A:
	movs r1, #0xad
	lsls r1, r1, #3
	adds r0, r7, r1
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _080264AC
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080264AC
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08009064
_080264AC:
	adds r4, #1
	cmp r4, #3
	ble _0802648A
	ldr r2, _0802650C @ =0x00000275
	adds r0, r7, r2
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080264D8
	ldr r2, _08026510 @ =FUN_08025654
	movs r3, #1
	adds r0, r5, #0
	adds r0, #0xa3
	movs r1, #0
	strb r3, [r0]
	adds r0, #0x55
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
_080264D8:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080264E8: .4byte 0x0203B400
_080264EC: .4byte 0x030046B8
_080264F0: .4byte 0x000003FF
_080264F4: .4byte 0x0000054C
_080264F8: .4byte 0x000002FF
_080264FC: .4byte 0x0000FFFC
_08026500: .4byte 0xFFFF0000
_08026504: .4byte 0x0000FFFF
_08026508: .4byte 0x00003001
_0802650C: .4byte 0x00000275
_08026510: .4byte FUN_08025654

	thumb_func_start FUN_08026514
FUN_08026514: @ 0x08026514
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov r8, r0
	adds r5, r1, #0
	mov r7, r8
	movs r0, #0x48
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802657C
	movs r4, #0
	strb r4, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r3, #0
	bl FUN_08022da8
	bl FUN_080591f4
	movs r1, #6
	cmp r0, #6
	ble _0802656C
	movs r1, #3
_0802656C:
	movs r2, #0xaa
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
_0802657C:
	mov r0, r8
	adds r0, #0xfc
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08026590
	b _08026728
_08026590:
	movs r2, #0x80
	lsls r2, r2, #1
	mov sl, r2
	mov r0, r8
	add r0, sl
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080265AA
	b _08026728
_080265AA:
	movs r6, #7
	ands r6, r5
	cmp r6, #0
	bne _08026632
	ldr r4, _08026670 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _08026674 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	ldr r5, _08026678 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r2, _0802667C @ =0x000001FF
	mov ip, r2
	mov r5, ip
	ands r0, r5
	mov r2, sb
	ldrh r2, [r2, #8]
	adds r0, r0, r2
	ldr r5, _08026680 @ =0xFFFFFF00
	adds r0, r0, r5
	lsls r0, r0, #0x10
	ldr r2, _08026684 @ =0xFFFF0000
	mov ip, r2
	mov r5, sb
	ldrh r5, [r5, #0xa]
	lsls r2, r5, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r2
	str r0, [sp, #0x1c]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	ldr r0, _08026678 @ =0x0203B400
	adds r1, r1, r0
	ldrb r1, [r1]
	mov r2, sb
	ldrh r0, [r2, #0xc]
	adds r0, r0, r1
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	mov r5, ip
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #0x20]
	ldr r2, _08026688 @ =0x00003001
	str r6, [sp]
	mov r0, sl
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	subs r0, #0xe
	str r0, [sp, #0x10]
	movs r0, #6
	str r0, [sp, #0x14]
	add r1, sp, #0x1c
	str r1, [sp, #0x18]
	movs r0, #1
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015ce0
_08026632:
	mov r0, r8
	adds r0, #0xc0
	ldr r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	movs r2, #0
	cmp r1, r0
	bhi _08026648
	movs r2, #1
_08026648:
	cmp r2, #0
	beq _0802668C
	ldr r5, [sp, #0x24]
	ldrh r1, [r5]
	mov r0, r8
	adds r0, #0x50
	strh r1, [r0]
	ldrh r1, [r5, #4]
	adds r0, #4
	strh r1, [r0]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _080266F2
	movs r0, #1
	strh r0, [r1]
	b _080266E6
	.align 2, 0
_08026670: .4byte 0x030046B8
_08026674: .4byte 0x000003FF
_08026678: .4byte 0x0203B400
_0802667C: .4byte 0x000001FF
_08026680: .4byte 0xFFFFFF00
_08026684: .4byte 0xFFFF0000
_08026688: .4byte 0x00003001
_0802668C:
	mov r0, r8
	adds r0, #0xc8
	ldr r2, _080266B8 @ =0x0000055C
	adds r1, r7, r2
	mov r3, r8
	adds r3, #0x58
	ldrb r4, [r0]
	ldrh r5, [r1]
	ldr r2, _080266BC @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080266C0
	asrs r1, r0, #0xc
	b _080266C6
	.align 2, 0
_080266B8: .4byte 0x0000055C
_080266BC: .4byte 0x085B0A08
_080266C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080266C6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080266DE
	asrs r0, r0, #0xc
	b _080266E4
_080266DE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080266E4:
	strh r0, [r3, #4]
_080266E6:
	movs r5, #0xb0
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _08026712
_080266F2:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	cmp r0, r2
	bhi _08026706
	adds r0, #0x20
	b _08026726
_08026706:
	strh r2, [r1]
	mov r1, r8
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _08026728
_08026712:
	movs r2, #0xac
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r3, [r1]
	movs r0, #0xc8
	lsls r0, r0, #1
	cmp r3, r0
	bls _08026728
	adds r0, r3, #0
	subs r0, #0x10
_08026726:
	strh r0, [r1]
_08026728:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08026738
FUN_08026738: @ 0x08026738
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	mov r8, r1
	adds r6, r5, #0
	adds r7, r5, #0
	adds r7, #0x48
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080267B4
	movs r4, #0
	strb r4, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r3, #8
	bl FUN_08022da8
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	ldr r2, _08026904 @ =0x00000542
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	movs r1, #0
	movs r4, #3
	adds r2, #0x27
	adds r0, r5, r2
_0802678E:
	strb r1, [r0]
	subs r0, #1
	subs r4, #1
	cmp r4, #0
	bge _0802678E
	ldr r0, _08026908 @ =0x0000054C
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xef
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	bl FUN_08024004
	ldr r0, _0802690C @ =0x000003BE
	bl PlaySound_0824078c
_080267B4:
	ldr r2, _08026910 @ =0x00000564
	adds r0, r6, r2
	movs r1, #0
	str r1, [r0]
	subs r2, #0x24
	adds r0, r6, r2
	strh r1, [r0]
	movs r2, #0xd
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0xb2
	ldrh r1, [r0]
	mov sb, r0
	cmp r1, #9
	bne _08026860
	movs r0, #0xac
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r1, [r2]
	ldr r0, _08026914 @ =0x000002FF
	cmp r1, r0
	bhi _080267EE
	adds r0, r1, #0
	adds r0, #0x10
	strh r0, [r2]
_080267EE:
	ldr r0, _08026918 @ =0x0000FFFC
	strh r0, [r7, #0x14]
	movs r3, #7
	mov r1, r8
	ands r3, r1
	cmp r3, #0
	bne _08026860
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldr r2, _0802691C @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _08026920 @ =0x000003FF
	ands r1, r0
	str r1, [r2]
	lsls r1, r1, #1
	ldr r2, _08026924 @ =0x0203B400
	adds r1, r1, r2
	add r0, sp, #0x1c
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08026928 @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	subs r1, #0x40
	lsls r1, r1, #0x10
	ldr r0, _0802692C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r2, _08026930 @ =0x00003001
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	movs r0, #8
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	subs r0, #6
	str r0, [sp, #0x10]
	str r3, [sp, #0x14]
	add r0, sp, #0x1c
	str r0, [sp, #0x18]
	movs r0, #1
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015ce0
_08026860:
	movs r4, #0
_08026862:
	movs r1, #0xad
	lsls r1, r1, #3
	adds r0, r6, r1
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _08026884
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08026884
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08009064
_08026884:
	adds r4, #1
	cmp r4, #3
	ble _08026862
	ldr r2, _08026934 @ =0x00000275
	adds r0, r6, r2
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08026956
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #8
	bne _0802693E
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #3
	bls _08026938
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	str r3, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #9
	bl FUN_08022da8
	bl FUN_08009154
	cmp r0, #0
	beq _08026956
	movs r4, #0
	ldr r1, _08026924 @ =0x0203B400
	mov ip, r1
	ldr r5, _0802691C @ =0x030046B8
	movs r0, #0xad
	lsls r0, r0, #3
	adds r2, r6, r0
	movs r3, #0x18
	ldr r7, _08026920 @ =0x000003FF
	movs r6, #3
_080268E2:
	ldr r0, [r5]
	adds r0, #1
	ands r0, r7
	str r0, [r5]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	adds r1, r2, r4
	ands r0, r6
	adds r0, r3, r0
	strb r0, [r1]
	adds r3, #3
	adds r4, #1
	cmp r4, #3
	ble _080268E2
	b _08026956
	.align 2, 0
_08026904: .4byte 0x00000542
_08026908: .4byte 0x0000054C
_0802690C: .4byte 0x000003BE
_08026910: .4byte 0x00000564
_08026914: .4byte 0x000002FF
_08026918: .4byte 0x0000FFFC
_0802691C: .4byte 0x030046B8
_08026920: .4byte 0x000003FF
_08026924: .4byte 0x0203B400
_08026928: .4byte 0xFFFF0000
_0802692C: .4byte 0x0000FFFF
_08026930: .4byte 0x00003001
_08026934: .4byte 0x00000275
_08026938:
	adds r0, #1
	strh r0, [r1]
	b _08026956
_0802693E:
	ldr r2, _08026964 @ =FUN_08025654
	movs r3, #1
	adds r0, r5, #0
	adds r0, #0xa3
	movs r1, #0
	strb r3, [r0]
	adds r0, #0x55
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
_08026956:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026964: .4byte FUN_08025654

	thumb_func_start FUN_08026968
FUN_08026968: @ 0x08026968
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	mov sb, r1
	adds r5, r4, #0
	adds r7, r4, #0
	adds r7, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08026A68
	movs r0, #0
	strb r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r2, r4, r3
	movs r6, #1
	mov r8, r6
	str r6, [sp]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0xa
	bl FUN_08022da8
	ldr r2, _08026A24 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08026A28 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08026A2C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #3
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08023530
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r3, r4
	mov sl, r3
	ldr r0, [r3]
	cmp r0, #0
	beq _08026A30
	movs r6, #0xc4
	lsls r6, r6, #1
	adds r3, r4, r6
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r6, #0
	ldrsh r2, [r1, r6]
	movs r6, #0
	ldrsh r0, [r3, r6]
	subs r2, r2, r0
	movs r0, #4
	ldrsh r1, [r1, r0]
	movs r6, #4
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r3, sl
	ldr r1, [r3]
	bl Div
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r1, r4, r6
	str r0, [r1]
	b _08026A3A
	.align 2, 0
_08026A24: .4byte 0x030046B8
_08026A28: .4byte 0x000003FF
_08026A2C: .4byte 0x0203B400
_08026A30:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r4, r1
	mov r2, r8
	str r2, [r0]
_08026A3A:
	ldr r3, _08026AE0 @ =0x0000016F
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08026A5C
	ldr r6, _08026AE4 @ =0x0000079C
	adds r0, r5, r6
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_08023090
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_08022fb8
_08026A5C:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0xbf
	lsls r0, r0, #1
	strh r0, [r1]
_08026A68:
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [sp, #8]
	movs r3, #0xba
	lsls r3, r3, #1
	adds r0, r5, r3
	asrs r1, r2, #0x10
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _08026AE8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	add r0, sp, #8
	bl FUN_0823b8ac
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r1, r5, r6
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #8
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r2, r6]
	movs r3, #0xc
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r6, r0, #0
	adds r3, r7, #0
	adds r3, #0x10
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08026AEC @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _08026AF0
	asrs r1, r0, #0xc
	b _08026AF6
	.align 2, 0
_08026AE0: .4byte 0x0000016F
_08026AE4: .4byte 0x0000079C
_08026AE8: .4byte 0x0000FFFF
_08026AEC: .4byte 0x085B0A08
_08026AF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08026AF6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08026B14 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r7, r0
	cmp r0, #0
	blt _08026B18
	asrs r0, r0, #0xc
	b _08026B1E
	.align 2, 0
_08026B14: .4byte 0x085B0A08
_08026B18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08026B1E:
	strh r0, [r3, #4]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	cmp sb, r2
	bge _08026B66
	cmp r2, #0
	beq _08026B56
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r6, #0
	ldrsh r0, [r0, r6]
	adds r1, #6
	adds r6, r5, r1
	movs r3, #0
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	bl Div
	ldrh r1, [r6]
	adds r1, r1, r0
	b _08026B6E
_08026B56:
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r1, [r0]
	movs r6, #0xac
	lsls r6, r6, #1
	adds r0, r5, r6
	b _08026B74
_08026B66:
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
_08026B6E:
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r5, r2
_08026B74:
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08023bd8
	movs r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	cmp sb, r0
	blt _08026C36
	ldr r6, _08026BA8 @ =0x0000016F
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _08026BB0
	ldr r0, _08026BAC @ =0x000003BB
	bl PlaySound_0824078c
	b _08026BB6
	.align 2, 0
_08026BA8: .4byte 0x0000016F
_08026BAC: .4byte 0x000003BB
_08026BB0:
	ldr r0, _08026C08 @ =0x000003BB
	bl PlaySound_0824078c
_08026BB6:
	ldr r0, _08026C0C @ =0x0000016F
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08026C14
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	lsls r0, r0, #5
	asrs r0, r0, #6
	str r0, [r1]
	ldr r1, _08026C10 @ =FUN_08026968
	movs r0, #0xf
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	movs r4, #7
_08026BF6:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08023bd8
	subs r4, #1
	cmp r4, #0
	bge _08026BF6
	b _08026C36
	.align 2, 0
_08026C08: .4byte 0x000003BB
_08026C0C: .4byte 0x0000016F
_08026C10: .4byte FUN_08026968
_08026C14:
	ldr r1, _08026C48 @ =FUN_08026c50
	movs r0, #0x10
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08026C4C @ =0x000003BD
	bl PlaySound_0824078c
_08026C36:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026C48: .4byte FUN_08026c50
_08026C4C: .4byte 0x000003BD

	thumb_func_start FUN_08026c50
FUN_08026c50: @ 0x08026C50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	mov sl, r1
	mov r7, r8
	movs r0, #0x48
	add r0, r8
	mov sb, r0
	mov r1, r8
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08026D08
	movs r5, #0
	strb r5, [r1]
	movs r4, #0xc4
	lsls r4, r4, #1
	add r4, r8
	mov r2, sb
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	str r0, [r4]
	str r1, [r4, #4]
	movs r3, #0xc8
	lsls r3, r3, #1
	add r3, r8
	movs r0, #0xd0
	lsls r0, r0, #3
	strh r0, [r3]
	movs r0, #0xc9
	lsls r0, r0, #1
	add r0, r8
	strh r5, [r0]
	movs r1, #0xca
	lsls r1, r1, #1
	add r1, r8
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r1]
	movs r0, #0xb1
	lsls r0, r0, #1
	add r0, r8
	strh r5, [r0]
	movs r6, #0xc0
	lsls r6, r6, #1
	add r6, r8
	movs r0, #8
	str r0, [r6]
	movs r0, #0
	ldrsh r2, [r3, r0]
	movs r1, #0
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r6]
	bl Div
	movs r1, #0xc2
	lsls r1, r1, #1
	add r1, r8
	str r0, [r1]
	movs r1, #0x96
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x8e
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	str r5, [sp, #4]
	mov r0, r8
	movs r3, #0xb
	bl FUN_08022da8
_08026D08:
	mov r3, sb
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [sp, #8]
	movs r0, #0xba
	lsls r0, r0, #1
	add r0, r8
	asrs r1, r2, #0x10
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _08026DB0 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	add r0, sp, #8
	bl FUN_0823b8ac
	movs r1, #0xa8
	lsls r1, r1, #3
	add r1, r8
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xd
	mov r3, r8
	adds r3, #0x98
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	mov r4, r8
	adds r4, #0x50
	movs r2, #0xc8
	lsls r2, r2, #1
	add r2, r8
	movs r5, #0
	ldrsh r1, [r2, r5]
	mov r6, sb
	movs r5, #8
	ldrsh r0, [r6, r5]
	subs r5, r1, r0
	movs r6, #4
	ldrsh r1, [r2, r6]
	movs r2, #4
	ldrsh r0, [r4, r2]
	subs r2, r1, r0
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r1, r0
	movs r4, #0xc0
	lsls r4, r4, #1
	add r4, r8
	ldr r0, [r4]
	adds r6, r0, #0
	muls r6, r0, r6
	adds r0, r6, #0
	adds r6, r3, #0
	cmp r1, r0
	blt _08026DE8
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0823785c
	adds r5, r0, #0
	mov r3, r8
	adds r3, #0x58
	ldr r4, [r4]
	ldr r2, _08026DB4 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08026DB8
	asrs r1, r0, #0xc
	b _08026DBE
	.align 2, 0
_08026DB0: .4byte 0x0000FFFF
_08026DB4: .4byte 0x085B0A08
_08026DB8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08026DBE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08026DDC @ =0x085B0A08
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08026DE0
	asrs r0, r0, #0xc
	b _08026DE6
	.align 2, 0
_08026DDC: .4byte 0x085B0A08
_08026DE0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08026DE6:
	strh r0, [r3, #4]
_08026DE8:
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r2, [r0]
	cmp sl, r2
	bge _08026E2E
	cmp r2, #0
	beq _08026E1E
	movs r5, #0xc9
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r3, #6
	adds r4, r7, r3
	movs r5, #0
	ldrsh r1, [r4, r5]
	subs r0, r0, r1
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	bl Div
	ldrh r1, [r4]
	adds r1, r1, r0
	b _08026E36
_08026E1E:
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r5, #0xac
	lsls r5, r5, #1
	adds r0, r7, r5
	b _08026E3C
_08026E2E:
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r1, [r0]
_08026E36:
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r7, r2
_08026E3C:
	strh r1, [r0]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	ble _08026E82
	mov r5, sl
	lsls r0, r5, #7
	bl Div
	ldr r2, _08026E6C @ =0x085B0A08
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #8
	cmp r0, #0
	blt _08026E70
	asrs r2, r0, #0xc
	b _08026E76
	.align 2, 0
_08026E6C: .4byte 0x085B0A08
_08026E70:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08026E76:
	movs r3, #0xac
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_08026E82:
	movs r5, #0xac
	lsls r5, r5, #1
	adds r4, r7, r5
	ldrh r1, [r4]
	ldr r0, _08026F50 @ =0x000001FF
	cmp r1, r0
	bls _08026E98
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08023bd8
_08026E98:
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _08026F60
	ldrh r1, [r4]
	ldr r0, _08026F54 @ =0x0000041A
	cmp r1, r0
	bhi _08026EC0
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _08026EC0
	adds r0, r1, #0
	movs r1, #1
	bl FUN_08023784
_08026EC0:
	movs r3, #0xac
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r0, _08026F58 @ =0x0000047E
	cmp r1, r0
	bhi _08026EE2
	movs r5, #0xae
	lsls r5, r5, #2
	adds r1, r7, r5
	ldrh r0, [r1]
	cmp r0, #0
	bne _08026EE2
	adds r0, r1, #0
	movs r1, #1
	bl FUN_08023784
_08026EE2:
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r0, #0xaf
	lsls r0, r0, #3
	cmp r1, r0
	bhi _08026F06
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _08026F06
	adds r0, r1, #0
	movs r1, #1
	bl FUN_08023784
_08026F06:
	movs r3, #0xac
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r1, r0
	bhi _08026F60
	movs r5, #0xe4
	lsls r5, r5, #2
	adds r1, r7, r5
	ldrh r0, [r1]
	cmp r0, #0
	bne _08026F2A
	adds r0, r1, #0
	movs r1, #2
	bl FUN_08023784
_08026F2A:
	movs r0, #0xff
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _08026F3E
	adds r0, r1, #0
	movs r1, #2
	bl FUN_08023784
_08026F3E:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #4
	bls _08026F5C
	subs r0, #4
	b _08026F5E
	.align 2, 0
_08026F50: .4byte 0x000001FF
_08026F54: .4byte 0x0000041A
_08026F58: .4byte 0x0000047E
_08026F5C:
	movs r0, #0
_08026F5E:
	strh r0, [r1]
_08026F60:
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _08026FD8
	movs r5, #0xe4
	lsls r5, r5, #2
	adds r1, r7, r5
	ldrh r0, [r1]
	cmp r0, #3
	bne _08026F8C
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	ldr r6, _08026F88 @ =0x0000054B
	adds r1, r7, r6
	b _08026FAE
	.align 2, 0
_08026F88: .4byte 0x0000054B
_08026F8C:
	cmp r0, #2
	bne _08026FC0
	ldr r0, [r1, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08026FA2
	subs r1, #0x12
	ldr r0, [r6]
	ands r0, r1
	b _08026FA8
_08026FA2:
	movs r1, #0x10
	ldr r0, [r6]
	orrs r0, r1
_08026FA8:
	str r0, [r6]
	ldr r0, _08026FBC @ =0x0000054B
	adds r1, r7, r0
_08026FAE:
	ldrb r0, [r1]
	cmp r0, #4
	bls _08026FC8
	subs r0, #4
	strb r0, [r1]
	b _08026FC8
	.align 2, 0
_08026FBC: .4byte 0x0000054B
_08026FC0:
	movs r1, #0x10
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
_08026FC8:
	ldr r1, _08027080 @ =0x0000027A
	adds r2, r7, r1
	ldr r3, _08027084 @ =0x0000054B
	adds r1, r7, r3
	ldrh r0, [r2]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2]
_08026FD8:
	mov r0, r8
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802701A
	movs r6, #0xb1
	lsls r6, r6, #1
	adds r5, r7, r6
	ldrh r4, [r5]
	cmp r4, #0
	bne _0802701A
	adds r0, r7, #0
	bl FUN_08023818
	ldr r0, _08027084 @ =0x0000054B
	adds r1, r7, r0
	movs r0, #0xc8
	strb r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r0, #2
	str r0, [sp]
	str r4, [sp, #4]
	mov r0, r8
	movs r3, #0x13
	bl FUN_08022da8
	movs r0, #1
	strh r0, [r5]
_0802701A:
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	cmp sl, r0
	blt _0802706E
	ldr r0, _08027088 @ =0x00000383
	bl PlaySound_0824078c
	bl FUN_080592a4
	bl FUN_08009154
	movs r6, #0xa9
	add r6, r8
	mov sb, r6
	mov r6, r8
	adds r6, #0xa3
	mov r7, r8
	adds r7, #0xf8
	mov r4, r8
	adds r4, #0x8c
	cmp r0, #0
	beq _0802705C
	movs r5, #0
_0802704C:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08009064
	adds r5, #1
	cmp r5, #3
	ble _0802704C
_0802705C:
	ldr r2, _0802708C @ =FUN_08027090
	movs r0, #0x11
	movs r1, #0
	strb r0, [r6]
	str r2, [r7]
	str r1, [r4]
	movs r0, #1
	mov r1, sb
	strb r0, [r1]
_0802706E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027080: .4byte 0x0000027A
_08027084: .4byte 0x0000054B
_08027088: .4byte 0x00000383
_0802708C: .4byte FUN_08027090

	thumb_func_start FUN_08027090
FUN_08027090: @ 0x08027090
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	mov r8, r1
	adds r6, r5, #0
	adds r7, r5, #0
	adds r7, #0x48
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080270DA
	movs r4, #0
	strb r4, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r3, #0x13
	bl FUN_08022da8
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r5, #0
	bl FUN_08023024
	ldr r1, _080270EC @ =0x0000054B
	adds r0, r5, r1
	strb r4, [r0]
_080270DA:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #4
	bls _080270F0
	subs r0, #4
	b _080270F2
	.align 2, 0
_080270EC: .4byte 0x0000054B
_080270F0:
	movs r0, #0
_080270F2:
	strh r0, [r1]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [sp, #8]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r6, r1
	asrs r1, r2, #0x10
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0802712C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	add r0, sp, #8
	bl FUN_0823b8ac
	mov r2, r8
	cmp r2, #7
	bgt _08027134
	ldr r0, _08027130 @ =0x0000054B
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #2
	b _0802714A
	.align 2, 0
_0802712C: .4byte 0x0000FFFF
_08027130: .4byte 0x0000054B
_08027134:
	ldr r2, _08027144 @ =0x0000054B
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #2
	bls _08027148
	subs r0, #2
	b _0802714A
	.align 2, 0
_08027144: .4byte 0x0000054B
_08027148:
	movs r0, #0
_0802714A:
	strb r0, [r1]
	ldr r0, _08027180 @ =0x0000027A
	adds r2, r6, r0
	ldr r0, _08027184 @ =0x0000054B
	adds r1, r6, r0
	ldrh r0, [r2]
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r1, [r0]
	movs r2, #0xd
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027180: .4byte 0x0000027A
_08027184: .4byte 0x0000054B

	thumb_func_start FUN_08027188
FUN_08027188: @ 0x08027188
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080271B2
	movs r3, #0
	strb r3, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	bl FUN_08022da8
_080271B2:
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r2, #0x1c
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080271e0
FUN_080271e0: @ 0x080271E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08027244
	movs r4, #0
	strb r4, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r2, r7, r0
	movs r6, #1
	str r6, [sp]
	str r4, [sp, #4]
	adds r0, r7, #0
	movs r3, #0
	bl FUN_08022da8
	movs r1, #0xac
	lsls r1, r1, #1
	adds r5, r7, r1
	movs r0, #0x80
	strh r0, [r5]
	ldr r1, _08027270 @ =0x000004D4
	adds r0, r7, r1
	movs r1, #0x60
	str r1, [sp]
	ldr r1, _08027274 @ =0x00001964
	str r1, [sp, #4]
	movs r1, #0x64
	str r1, [sp, #8]
	movs r1, #6
	str r1, [sp, #0xc]
	str r6, [sp, #0x10]
	movs r1, #0x60
	movs r2, #0x60
	movs r3, #0x60
	bl FUN_08013cd8
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r5]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
_08027244:
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	movs r2, #0xc
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027270: .4byte 0x000004D4
_08027274: .4byte 0x00001964

	thumb_func_start FUN_08027278
FUN_08027278: @ 0x08027278
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080272D6
	movs r4, #0
	strb r4, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	movs r5, #1
	str r5, [sp]
	str r4, [sp, #4]
	adds r0, r6, #0
	movs r3, #0x11
	bl FUN_08022c34
	ldr r1, _08027304 @ =0x000004D4
	adds r0, r6, r1
	movs r1, #0x30
	str r1, [sp]
	ldr r1, _08027308 @ =0x00001964
	str r1, [sp, #4]
	movs r1, #0x64
	str r1, [sp, #8]
	movs r1, #6
	str r1, [sp, #0xc]
	str r5, [sp, #0x10]
	movs r1, #0x30
	movs r2, #0x30
	movs r3, #0x30
	bl FUN_08013cd8
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r6, r0
	subs r0, #0x58
	strh r0, [r1]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
_080272D6:
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	movs r2, #0xc
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08027304: .4byte 0x000004D4
_08027308: .4byte 0x00001964

	thumb_func_start FUN_0802730c
FUN_0802730c: @ 0x0802730C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	adds r7, r1, #0
	movs r0, #0x48
	adds r0, r0, r6
	mov r8, r0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802739C
	movs r4, #0
	strb r4, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r5, #1
	str r5, [sp]
	str r4, [sp, #4]
	adds r0, r6, #0
	movs r3, #0x11
	bl FUN_08022c34
	adds r2, r6, #0
	adds r2, #0xcc
	mov r3, r8
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0x10
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080273E4 @ =0x000004D4
	adds r0, r6, r1
	movs r1, #0x30
	str r1, [sp]
	ldr r1, _080273E8 @ =0x00001964
	str r1, [sp, #4]
	movs r1, #0x64
	str r1, [sp, #8]
	movs r1, #6
	str r1, [sp, #0xc]
	str r5, [sp, #0x10]
	movs r1, #0x30
	movs r2, #0x30
	movs r3, #0x30
	bl FUN_08013cd8
	movs r2, #0xac
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0xad
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	movs r0, #0xca
	lsls r0, r0, #2
	bl PlaySound_0824078c
_0802739C:
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _080273EC @ =0x0001000C
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08027446
	adds r0, r6, #0
	adds r0, #0xcc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, r8
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	cmp r7, #0x1f
	ble _080273F0
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _08027446
	.align 2, 0
_080273E4: .4byte 0x000004D4
_080273E8: .4byte 0x00001964
_080273EC: .4byte 0x0001000C
_080273F0:
	movs r1, #3
	bics r1, r7
	movs r0, #0x20
	subs r0, r0, r7
	adds r4, r6, #0
	adds r4, #0x58
	lsls r5, r1, #6
	lsls r6, r0, #3
	ldr r2, _0802741C @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _08027420
	asrs r3, r0, #0xc
	b _08027426
	.align 2, 0
_0802741C: .4byte 0x085B0A08
_08027420:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08027426:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802743E
	asrs r0, r0, #0xc
	b _08027444
_0802743E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08027444:
	strh r0, [r4, #4]
_08027446:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08027454
FUN_08027454: @ 0x08027454
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	adds r7, r1, #0
	movs r0, #0x48
	adds r0, r0, r6
	mov r8, r0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080274D8
	movs r4, #0
	strb r4, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r5, #1
	str r5, [sp]
	str r4, [sp, #4]
	adds r0, r6, #0
	movs r3, #0x11
	bl FUN_08022c34
	adds r2, r6, #0
	adds r2, #0xcc
	mov r3, r8
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _08027538 @ =0x000004D4
	adds r0, r6, r1
	movs r1, #0x30
	str r1, [sp]
	ldr r1, _0802753C @ =0x00001964
	str r1, [sp, #4]
	movs r1, #0x64
	str r1, [sp, #8]
	movs r1, #6
	str r1, [sp, #0xc]
	str r5, [sp, #0x10]
	movs r1, #0x30
	movs r2, #0x30
	movs r3, #0x30
	bl FUN_08013cd8
	movs r2, #0xac
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0xad
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	movs r0, #0xca
	lsls r0, r0, #2
	bl PlaySound_0824078c
_080274D8:
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _08027540 @ =0x0001000C
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802757A
	adds r0, r6, #0
	adds r0, #0xcc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, r8
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	movs r0, #3
	ands r0, r7
	adds r3, r6, #0
	adds r3, #0x58
	lsls r4, r0, #6
	lsls r5, r7, #3
	ldr r2, _08027544 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08027548
	asrs r1, r0, #0xc
	b _0802754E
	.align 2, 0
_08027538: .4byte 0x000004D4
_0802753C: .4byte 0x00001964
_08027540: .4byte 0x0001000C
_08027544: .4byte 0x085B0A08
_08027548:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802754E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08027566
	asrs r0, r0, #0xc
	b _0802756C
_08027566:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802756C:
	strh r0, [r3, #4]
	cmp r7, #0x1f
	ble _0802757A
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802757A:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08027588
FUN_08027588: @ 0x08027588
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa7
	movs r0, #0
	strb r0, [r1]
	movs r1, #4
	ldr r0, _080275AC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080275A6
	adds r0, r2, #0
	bl FUN_08022f78
_080275A6:
	pop {r0}
	bx r0
	.align 2, 0
_080275AC: .4byte 0x03002BC0

	thumb_func_start FUN_080275b0
FUN_080275b0: @ 0x080275B0
	push {lr}
	mov ip, r0
	mov r2, ip
	adds r2, #0xa2
	ldrb r0, [r2]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x16
	bhi _080275EC
	ldr r1, _080275E8 @ =0x085AAB60
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
	b _080275EE
	.align 2, 0
_080275E8: .4byte 0x085AAB60
_080275EC:
	movs r0, #0
_080275EE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080275f4
FUN_080275f4: @ 0x080275F4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #0xf4
	lsls r0, r0, #1
	adds r0, r0, r4
	mov ip, r0
	movs r1, #0xa8
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r2, #0
	ldrsh r6, [r0, r2]
	movs r1, #0
	mov sb, r1
	mov r2, sb
	strh r2, [r0]
	cmp r6, #0
	bgt _08027620
	b _08027784
_08027620:
	ldr r0, _08027704 @ =0x00000544
	adds r7, r4, r0
	ldr r1, _08027708 @ =0x00000546
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r1, r1, r6
	ldrh r0, [r7]
	subs r0, r0, r1
	strh r0, [r7]
	adds r5, r4, #0
	adds r5, #0x90
	ldrh r0, [r5]
	subs r0, r0, r6
	strh r0, [r5]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xa
	strh r0, [r1]
	ldr r2, _0802770C @ =0x00000292
	adds r1, r4, r2
	ldr r0, _08027710 @ =0x00000223
	strh r0, [r1]
	adds r0, #0x7d
	adds r1, r4, r0
	movs r2, #0xae
	lsls r2, r2, #3
	adds r0, r4, r2
	str r0, [r1]
	ldr r3, _08027714 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _08027718 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	adds r3, r4, #0
	adds r3, #0x50
	add r0, sp, #8
	str r0, [sp]
	movs r1, #1
	mov r8, r1
	str r1, [sp, #4]
	mov r0, ip
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0805fe7c
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bgt _0802772C
	ldr r0, _0802771C @ =0x000003BA
	bl PlaySound_0824078c
	mov r0, sb
	strh r0, [r5]
	movs r2, #2
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _08027720 @ =0x0000016F
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r4, r1
	mov r2, sb
	strh r2, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0x80
	str r0, [r1]
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	ldr r2, _08027724 @ =0x00000167
	adds r1, r4, r2
	strb r0, [r1]
	ldr r1, _08027728 @ =FUN_08026968
	adds r2, r4, #0
	adds r2, #0xa3
	movs r0, #0xf
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	mov r1, sb
	str r1, [r0]
	adds r0, #0x1d
	mov r2, r8
	strb r2, [r0]
	bl FUN_08059248
	movs r0, #1
	b _08027786
	.align 2, 0
_08027704: .4byte 0x00000544
_08027708: .4byte 0x00000546
_0802770C: .4byte 0x00000292
_08027710: .4byte 0x00000223
_08027714: .4byte 0xFFFF0000
_08027718: .4byte 0x0000FFFF
_0802771C: .4byte 0x000003BA
_08027720: .4byte 0x0000016F
_08027724: .4byte 0x00000167
_08027728: .4byte FUN_08026968
_0802772C:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_0824078c
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802774C
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08024100
_0802774C:
	movs r2, #0
	ldrsh r0, [r7, r2]
	cmp r0, #0
	bgt _08027784
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	mov r2, r8
	orrs r0, r2
	str r0, [r1]
	ldr r1, _08027780 @ =FUN_08026738
	movs r0, #0xe
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	mov r1, sb
	str r1, [r0]
	adds r0, #0x1d
	mov r2, r8
	strb r2, [r0]
	movs r0, #1
	b _08027786
	.align 2, 0
_08027780: .4byte FUN_08026738
_08027784:
	movs r0, #0
_08027786:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Duneyrr_Update
Duneyrr_Update: @ 0x08027794
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08024500
	adds r0, r4, #0
	bl FUN_08025630
	adds r0, r4, #0
	bl FUN_08027588
	adds r0, r4, #0
	bl FUN_080245e4
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Duneyrr_Destroy
Duneyrr_Destroy: @ 0x080277B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080277E8 @ =0x000004D4
	adds r0, r4, r1
	bl FUN_08013c70
	adds r0, r4, #0
	bl FUN_080234dc
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	adds r0, r4, #0
	bl FUN_08023ba0
	adds r0, r4, #0
	bl FUN_08022b04
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080277E8: .4byte 0x000004D4

	thumb_func_start Duneyrr_Init
Duneyrr_Init: @ 0x080277EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r6, r0, #0
	mov r8, r1
	adds r7, r6, #0
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	adds r0, r6, #0
	mov r1, sb
	bl FUN_08022a0c
	ldr r0, _08027830 @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _08027834
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r6, r1
	str r2, [r0]
	movs r3, #0x86
	lsls r3, r3, #1
	adds r1, r6, r3
	adds r0, r2, #0
	adds r0, #0x2c
	str r0, [r1]
	b _08027844
	.align 2, 0
_08027830: .4byte 0x03002BE0
_08027834:
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r6, r4
	str r2, [r0]
	movs r5, #0x86
	lsls r5, r5, #1
	adds r0, r6, r5
	str r2, [r0]
_08027844:
	ldr r0, _080278D4 @ =0x0000CB05
	ldr r1, _080278D8 @ =0x0000D3CA
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _08027854
	b _08027E18
_08027854:
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r0, r0, r6
	mov sl, r0
	mov r2, sl
	adds r1, r3, #0
	ldm r1!, {r0, r4, r5}
	stm r2!, {r0, r4, r5}
	ldm r1!, {r0, r4, r5}
	stm r2!, {r0, r4, r5}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	mov r0, sl
	adds r1, r3, #0
	bl OpenSpriteSetFile
	movs r0, #0xee
	lsls r0, r0, #3
	adds r1, r6, r0
	subs r0, #0xf0
	strh r0, [r1]
	ldr r2, _080278DC @ =0x00000772
	adds r1, r6, r2
	movs r0, #0x80
	strh r0, [r1]
	ldr r3, _080278E0 @ =0x00000774
	adds r1, r6, r3
	movs r0, #0xc0
	lsls r0, r0, #3
	strh r0, [r1]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080278EC
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080278E4 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080278E8 @ =0x0000FFFF
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
	adds r4, r0, #0
	b _08027914
	.align 2, 0
_080278D4: .4byte 0x0000CB05
_080278D8: .4byte 0x0000D3CA
_080278DC: .4byte 0x00000772
_080278E0: .4byte 0x00000774
_080278E4: .4byte 0xFFFF0000
_080278E8: .4byte 0x0000FFFF
_080278EC:
	ldr r0, _08027940 @ =0x030046A0
	ldr r3, [r0]
	ldrh r0, [r3, #0x30]
	ldr r4, _08027944 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r2, [r3, #0x32]
	lsls r2, r2, #0x10
	ldr r0, _08027948 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x1c]
	ldrh r1, [r3, #0x34]
	ldr r0, [sp, #0x20]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r4, #0x40
_08027914:
	movs r0, #0x73
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _08027950
	bl Script_GetValue
	str r0, [sp, #0x24]
	bl Script_GetValue
	movs r5, #0xef
	lsls r5, r5, #3
	adds r1, r6, r5
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _0802794C @ =0x0000077A
	adds r1, r6, r2
	strh r0, [r1]
	b _08027966
	.align 2, 0
_08027940: .4byte 0x030046A0
_08027944: .4byte 0xFFFF0000
_08027948: .4byte 0x0000FFFF
_0802794C: .4byte 0x0000077A
_08027950:
	movs r3, #0xfa
	lsls r3, r3, #1
	str r3, [sp, #0x24]
	movs r5, #0xef
	lsls r5, r5, #3
	adds r0, r6, r5
	movs r1, #0xa
	strh r1, [r0]
	ldr r1, _080279C4 @ =0x0000077A
	adds r0, r6, r1
	strh r2, [r0]
_08027966:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _080279E0
	bl Script_GetValue
	ldr r2, _080279C8 @ =0x0000077E
	adds r1, r6, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0xf0
	lsls r3, r3, #3
	adds r1, r6, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r5, _080279CC @ =0x00000782
	adds r1, r6, r5
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080279D0 @ =0x00000784
	adds r1, r6, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _080279D4 @ =0x00000786
	adds r1, r6, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #6
	adds r1, r6, r5
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080279D8 @ =0x0000078A
	adds r1, r6, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _080279DC @ =0x0000078C
	adds r1, r6, r3
	strh r0, [r1]
	b _08027A1E
	.align 2, 0
_080279C4: .4byte 0x0000077A
_080279C8: .4byte 0x0000077E
_080279CC: .4byte 0x00000782
_080279D0: .4byte 0x00000784
_080279D4: .4byte 0x00000786
_080279D8: .4byte 0x0000078A
_080279DC: .4byte 0x0000078C
_080279E0:
	ldr r5, _08027AA8 @ =0x0000077E
	adds r0, r6, r5
	movs r3, #0x23
	strh r3, [r0]
	movs r1, #0xf0
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #0x32
	strh r1, [r0]
	ldr r2, _08027AAC @ =0x00000782
	adds r0, r6, r2
	movs r2, #0x3c
	strh r2, [r0]
	adds r5, #6
	adds r0, r6, r5
	strh r1, [r0]
	ldr r0, _08027AB0 @ =0x00000786
	adds r1, r6, r0
	movs r0, #0xf0
	strh r0, [r1]
	movs r1, #0xf1
	lsls r1, r1, #3
	adds r0, r6, r1
	strh r2, [r0]
	ldr r2, _08027AB4 @ =0x0000078A
	adds r1, r6, r2
	movs r0, #0xd
	strh r0, [r1]
	adds r5, #8
	adds r0, r6, r5
	strh r3, [r0]
_08027A1E:
	str r4, [sp]
	adds r0, r7, #0
	mov r1, r8
	mov r2, sb
	add r3, sp, #0x1c
	bl Boss_Init_08022a70
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	mov r8, r2
	strb r4, [r0]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	movs r3, #0xab
	adds r3, r3, r7
	mov sl, r3
	strb r0, [r3]
	movs r5, #0x96
	lsls r5, r5, #2
	adds r4, r6, r5
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r1, #2
	str r1, [sp]
	mov r2, r8
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r3, sp, #0x1c
	str r3, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	movs r0, #1
	mov sb, r0
	str r0, [sp]
	mov r1, r8
	str r1, [sp, #4]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl FUN_08022da8
	mov r3, sl
	ldrb r2, [r3]
	cmp r2, #0
	bne _08027A90
	b _08027BAC
_08027A90:
	movs r0, #0x44
	movs r1, #1
	bl Script_GetKeywordValue
	adds r1, r0, #0
	cmp r1, #1
	beq _08027B10
	cmp r1, #1
	bgt _08027AB8
	cmp r1, #0
	beq _08027ABE
	b _08027BF2
	.align 2, 0
_08027AA8: .4byte 0x0000077E
_08027AAC: .4byte 0x00000782
_08027AB0: .4byte 0x00000786
_08027AB4: .4byte 0x0000078A
_08027AB8:
	cmp r1, #2
	beq _08027B60
	b _08027BF2
_08027ABE:
	adds r0, r7, #0
	adds r0, #0xa4
	movs r4, #2
	strb r4, [r0]
	adds r0, #1
	mov r5, r8
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #0x16
	mov r1, r8
	str r1, [r0]
	subs r0, #0x14
	mov r2, sb
	strb r2, [r0]
	ldr r1, _08027B0C @ =FUN_08027188
	movs r0, #0x12
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	mov r3, r8
	str r3, [r0]
	adds r0, #0x1d
	mov r4, sb
	strb r4, [r0]
	movs r5, #0xac
	lsls r5, r5, #1
	adds r1, r6, r5
	movs r0, #0x80
	strh r0, [r1]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r3, [r0]
	b _08027BF2
	.align 2, 0
_08027B0C: .4byte FUN_08027188
_08027B10:
	adds r0, r7, #0
	adds r0, #0xa4
	movs r2, #2
	strb r2, [r0]
	adds r0, #1
	mov r3, r8
	strb r3, [r0]
	adds r0, #1
	mov r4, sb
	strb r4, [r0]
	adds r0, #0x16
	mov r5, r8
	str r5, [r0]
	subs r0, #0x14
	strb r4, [r0]
	ldr r1, _08027B5C @ =FUN_080271e0
	movs r0, #0x13
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	adds r0, #0x1d
	strb r4, [r0]
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x80
	strh r0, [r1]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	b _08027BF2
	.align 2, 0
_08027B5C: .4byte FUN_080271e0
_08027B60:
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	mov r2, r8
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	mov r3, r8
	str r3, [r0]
	subs r0, #0x14
	mov r4, sb
	strb r4, [r0]
	ldr r1, _08027BA8 @ =FUN_08027278
	movs r0, #0x14
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r4, [r0]
	movs r5, #0xac
	lsls r5, r5, #1
	adds r0, r6, r5
	strh r3, [r0]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, r8
	b _08027BF0
	.align 2, 0
_08027BA8: .4byte FUN_08027278
_08027BAC:
	movs r1, #0x78
	adds r0, r6, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	mov r3, sb
	strb r3, [r0]
	ldr r4, _08027C44 @ =0x0000055A
	adds r0, r6, r4
	strh r1, [r0]
	ldr r1, _08027C48 @ =FUN_08025654
	adds r0, r7, #0
	adds r0, #0xa3
	strb r3, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	movs r5, #0xac
	lsls r5, r5, #1
	adds r1, r6, r5
	movs r0, #0x80
	strh r0, [r1]
	movs r1, #0xad
	lsls r1, r1, #1
	adds r0, r6, r1
_08027BF0:
	strh r2, [r0]
_08027BF2:
	ldr r1, _08027C4C @ =FUN_080275f4
	adds r0, r7, #0
	adds r0, #0xfc
	str r1, [r0]
	ldr r1, _08027C50 @ =FUN_080275b0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r7, r2
	str r1, [r0]
	movs r3, #0xef
	lsls r3, r3, #3
	adds r4, r6, r3
	ldrh r3, [r4]
	adds r0, r7, #0
	ldr r1, [sp, #0x24]
	adds r2, r1, #0
	bl FUN_08022b2c
	adds r0, r6, #0
	bl FUN_080241e4
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_08024294
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _08027C54
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r2, r0, #0
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08022fac
	b _08027C5E
	.align 2, 0
_08027C44: .4byte 0x0000055A
_08027C48: .4byte FUN_08025654
_08027C4C: .4byte FUN_080275f4
_08027C50: .4byte FUN_080275b0
_08027C54:
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08022fac
_08027C5E:
	movs r0, #0x41
	bl prepare_08231510
	adds r4, r7, #0
	adds r4, #0xde
	cmp r0, #0
	beq _08027C8C
	movs r5, #0
	b _08027C80
_08027C70:
	bl Script_GetValue
	lsls r2, r5, #2
	adds r1, r7, #0
	adds r1, #0xe8
	adds r1, r1, r2
	str r0, [r1]
	adds r5, #1
_08027C80:
	cmp r5, #3
	bgt _08027C8C
	bl VM_GetPC
	cmp r0, #0
	bne _08027C70
_08027C8C:
	movs r0, #0x65
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _08027CD8
	bl Script_GetValue
	ldr r5, _08027CD0 @ =0x0000078E
	adds r1, r6, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xf2
	lsls r2, r2, #3
	adds r1, r6, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _08027CD4 @ =0x00000792
	adds r1, r6, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #6
	adds r1, r6, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xf3
	lsls r2, r2, #3
	adds r1, r6, r2
	str r0, [r1]
	b _08027CFE
	.align 2, 0
_08027CD0: .4byte 0x0000078E
_08027CD4: .4byte 0x00000792
_08027CD8:
	ldr r3, _08027D8C @ =0x0000078E
	adds r1, r6, r3
	movs r0, #0x1e
	strh r0, [r1]
	movs r5, #0xf2
	lsls r5, r5, #3
	adds r0, r6, r5
	strh r2, [r0]
	ldr r0, _08027D90 @ =0x00000792
	adds r1, r6, r0
	movs r0, #0x1c
	strh r0, [r1]
	adds r3, #6
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	adds r5, #8
	adds r0, r6, r5
	str r2, [r0]
_08027CFE:
	movs r0, #0x4b
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _08027D94 @ =0x0000079C
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0x78
	movs r1, #2
	bl Script_GetKeywordValue
	movs r5, #0
	strb r0, [r4]
	ldr r3, _08027D98 @ =0x00000796
	adds r1, r6, r3
	movs r0, #0xfa
	lsls r0, r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_08024324
	adds r0, r6, #0
	bl FUN_0802378c
	ldr r0, _08027D9C @ =0x000004D4
	adds r4, r6, r0
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0x60
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _08027DA0 @ =0x00001964
	str r0, [sp, #8]
	movs r0, #0x64
	str r0, [sp, #0xc]
	movs r0, #6
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	adds r0, r4, #0
	movs r2, #0x60
	movs r3, #0x60
	bl FUN_08013ba8
	ldr r1, _08027DA4 @ =0x00001C1B
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08013c94
	movs r0, #0x6a
	bl prepare_08231510
	cmp r0, #0
	beq _08027DB4
	bl Script_GetValue
	ldr r3, _08027DA8 @ =0x00000542
	adds r1, r6, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _08027DAC @ =0x00000546
	adds r1, r6, r4
	strh r0, [r1]
	bl Script_GetValue
	ldr r5, _08027DB0 @ =0x0000077C
	adds r1, r6, r5
	b _08027DCA
	.align 2, 0
_08027D8C: .4byte 0x0000078E
_08027D90: .4byte 0x00000792
_08027D94: .4byte 0x0000079C
_08027D98: .4byte 0x00000796
_08027D9C: .4byte 0x000004D4
_08027DA0: .4byte 0x00001964
_08027DA4: .4byte 0x00001C1B
_08027DA8: .4byte 0x00000542
_08027DAC: .4byte 0x00000546
_08027DB0: .4byte 0x0000077C
_08027DB4:
	ldr r0, _08027E20 @ =0x00000542
	adds r1, r6, r0
	movs r0, #0x96
	strh r0, [r1]
	ldr r2, _08027E24 @ =0x00000546
	adds r1, r6, r2
	movs r0, #0x32
	strh r0, [r1]
	ldr r3, _08027E28 @ =0x0000077C
	adds r1, r6, r3
	movs r0, #3
_08027DCA:
	strh r0, [r1]
	ldr r4, _08027E20 @ =0x00000542
	adds r0, r6, r4
	ldrh r1, [r0]
	ldr r5, _08027E2C @ =0x00000544
	adds r0, r6, r5
	strh r1, [r0]
	ldr r1, _08027E30 @ =0x0000078C
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, _08027E34 @ =0x0000078A
	adds r1, r6, r3
	movs r4, #0
	ldrsh r3, [r1, r4]
	movs r1, #0x1e
	movs r2, #0xf
	bl FUN_08059a1c
	adds r5, #0x28
	adds r1, r6, r5
	str r0, [r1]
	cmp r0, #0
	beq _08027E18
	ldr r1, _08027E38 @ =0x00000792
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, _08027E3C @ =0x00000794
	adds r1, r6, r3
	ldrh r1, [r1]
	movs r4, #0xf3
	lsls r4, r4, #3
	adds r2, r6, r4
	ldr r2, [r2]
	bl FUN_08058ffc
	cmp r0, #0
	bne _08027E40
_08027E18:
	movs r0, #1
	rsbs r0, r0, #0
	b _08027E66
	.align 2, 0
_08027E20: .4byte 0x00000542
_08027E24: .4byte 0x00000546
_08027E28: .4byte 0x0000077C
_08027E2C: .4byte 0x00000544
_08027E30: .4byte 0x0000078C
_08027E34: .4byte 0x0000078A
_08027E38: .4byte 0x00000792
_08027E3C: .4byte 0x00000794
_08027E40:
	ldr r0, _08027E78 @ =0x03003584
	ldr r0, [r0]
	movs r5, #0x99
	lsls r5, r5, #6
	adds r7, r0, r5
	movs r0, #0xae
	lsls r0, r0, #3
	adds r4, r6, r0
	movs r5, #0xf
_08027E52:
	adds r0, r7, #0
	adds r1, r4, #0
	ldr r2, _08027E7C @ =0x04000008
	bl CpuSet
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _08027E52
	movs r0, #0
_08027E66:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08027E78: .4byte 0x03003584
_08027E7C: .4byte 0x04000008

