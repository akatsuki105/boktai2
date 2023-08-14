	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0824c598
FUN_0824c598: @ 0x0824C598
	push {r7, lr}
	mov r7, sp
	bl FUN_0824ce38
	ldr r0, _0824C5AC @ =0x030026CA
	movs r1, #0
	strb r1, [r0]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824C5AC: .4byte 0x030026CA

	thumb_func_start FUN_0824c5b0
FUN_0824c5b0: @ 0x0824C5B0
	push {r7, lr}
	mov r7, sp
	bl FUN_0824ce4c
	ldr r0, _0824C5C4 @ =0x030026CA
	movs r1, #1
	strb r1, [r0]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824C5C4: .4byte 0x030026CA

	thumb_func_start FUN_0824c5c8
FUN_0824c5c8: @ 0x0824C5C8
	push {r7, lr}
	sub sp, #0x10
	mov r7, sp
	adds r1, r7, #4
	adds r0, r1, #0
	bl FUN_0824c724
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0
	bne _0824C5E2
	movs r0, #0
	b _0824C696
_0824C5E2:
	adds r0, r7, #0
	movs r1, #0
	strb r1, [r0]
	adds r0, r7, #4
	ldrb r1, [r0, #7]
	movs r2, #0xc0
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0x80
	beq _0824C612
	adds r0, r7, #4
	ldrb r1, [r0, #7]
	movs r2, #0xc0
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0
	bne _0824C630
	b _0824C612
_0824C612:
	bl FUN_0824c6a0
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0
	bne _0824C622
	movs r0, #0
	b _0824C696
_0824C622:
	adds r1, r7, #0
	adds r0, r7, #0
	adds r1, r7, #0
	ldrb r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strb r2, [r0]
_0824C630:
	adds r1, r7, #4
	adds r0, r1, #0
	bl FUN_0824c9e4
	adds r0, r7, #4
	ldrb r1, [r0, #6]
	movs r2, #0x80
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0
	beq _0824C67E
	bl FUN_0824c6a0
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0
	bne _0824C670
	adds r0, r7, #0
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r1, r0, #0
	movs r2, #0xf
	adds r0, r1, #0
	bics r0, r2
	adds r1, r0, #0
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	adds r0, r1, #0
	b _0824C696
_0824C670:
	adds r1, r7, #0
	adds r0, r7, #0
	adds r1, r7, #0
	ldrb r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strb r2, [r0]
_0824C67E:
	adds r0, r7, #0
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r1, r0, #0
	movs r2, #1
	adds r0, r1, #0
	orrs r0, r2
	adds r1, r0, #0
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	adds r0, r1, #0
	b _0824C696
_0824C696:
	add sp, #0x10
	pop {r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0824c6a0
FUN_0824c6a0: @ 0x0824C6A0
	push {r7, lr}
	sub sp, #0x10
	mov r7, sp
	ldr r0, _0824C6B4 @ =0x030026CA
	ldrb r1, [r0]
	cmp r1, #1
	bne _0824C6B8
	movs r0, #0
	b _0824C71C
	.align 2, 0
_0824C6B4: .4byte 0x030026CA
_0824C6B8:
	ldr r0, _0824C710 @ =0x030026CA
	movs r1, #1
	strb r1, [r0]
	ldr r0, _0824C714 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C714 @ =0x080000C4
	movs r1, #5
	strh r1, [r0]
	ldr r0, _0824C718 @ =0x080000C6
	movs r1, #7
	strh r1, [r0]
	movs r0, #0x60
	bl FUN_0824cc68
	ldr r0, _0824C714 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C714 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C710 @ =0x030026CA
	movs r1, #0
	strb r1, [r0]
	adds r0, r7, #4
	ldrb r1, [r0, #7]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x40
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0, #7]
	adds r1, r7, #4
	adds r0, r1, #0
	bl FUN_0824c7f0
	adds r1, r7, #0
	strb r0, [r1]
	adds r0, r7, #0
	ldrb r1, [r0]
	adds r0, r1, #0
	b _0824C71C
	.align 2, 0
_0824C710: .4byte 0x030026CA
_0824C714: .4byte 0x080000C4
_0824C718: .4byte 0x080000C6
_0824C71C:
	add sp, #0x10
	pop {r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824c724
FUN_0824c724: @ 0x0824C724
	push {r4, r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r0, _0824C738 @ =0x030026CA
	ldrb r1, [r0]
	cmp r1, #1
	bne _0824C73C
	movs r0, #0
	b _0824C7E8
	.align 2, 0
_0824C738: .4byte 0x030026CA
_0824C73C:
	ldr r0, _0824C7DC @ =0x030026CA
	movs r1, #1
	strb r1, [r0]
	ldr r0, _0824C7E0 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C7E0 @ =0x080000C4
	movs r1, #5
	strh r1, [r0]
	ldr r0, _0824C7E4 @ =0x080000C6
	movs r1, #7
	strh r1, [r0]
	movs r0, #0x63
	bl FUN_0824cc68
	ldr r0, _0824C7E4 @ =0x080000C6
	movs r1, #5
	strh r1, [r0]
	bl FUN_0824cdac
	adds r1, r7, #4
	strb r0, [r1]
	ldr r0, [r7]
	adds r1, r7, #4
	ldrb r2, [r1]
	movs r3, #0xc0
	adds r1, r2, #0
	ands r1, r3
	adds r2, r7, #4
	ldrb r3, [r2]
	movs r4, #0x20
	adds r2, r3, #0
	ands r2, r4
	adds r4, r2, #0
	lsls r3, r4, #0x18
	lsrs r2, r3, #0x18
	lsrs r3, r2, #3
	adds r2, r3, #0
	orrs r1, r2
	adds r2, r7, #4
	ldrb r3, [r2]
	movs r4, #8
	adds r2, r3, #0
	ands r2, r4
	adds r4, r2, #0
	lsls r3, r4, #0x18
	lsrs r2, r3, #0x18
	lsrs r3, r2, #2
	adds r2, r3, #0
	orrs r1, r2
	adds r2, r7, #4
	ldrb r3, [r2]
	movs r4, #2
	adds r2, r3, #0
	ands r2, r4
	adds r4, r2, #0
	lsls r3, r4, #0x18
	lsrs r2, r3, #0x18
	lsrs r3, r2, #1
	adds r2, r3, #0
	orrs r1, r2
	ldrb r2, [r0, #7]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0, #7]
	ldr r0, _0824C7E0 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C7E0 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C7DC @ =0x030026CA
	movs r1, #0
	strb r1, [r0]
	movs r0, #1
	b _0824C7E8
	.align 2, 0
_0824C7DC: .4byte 0x030026CA
_0824C7E0: .4byte 0x080000C4
_0824C7E4: .4byte 0x080000C6
_0824C7E8:
	add sp, #8
	pop {r4, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824c7f0
FUN_0824c7f0: @ 0x0824C7F0
	push {r4, r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r0, _0824C804 @ =0x030026CA
	ldrb r1, [r0]
	cmp r1, #1
	bne _0824C808
	movs r0, #0
	b _0824C890
	.align 2, 0
_0824C804: .4byte 0x030026CA
_0824C808:
	ldr r0, _0824C884 @ =0x030026CA
	movs r1, #1
	strb r1, [r0]
	ldr r0, _0824C888 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C888 @ =0x080000C4
	movs r1, #5
	strh r1, [r0]
	adds r0, r7, #4
	ldr r1, [r7]
	ldrb r2, [r1, #7]
	movs r3, #4
	adds r1, r2, #0
	ands r1, r3
	adds r2, r1, #0
	lsls r1, r2, #3
	ldr r2, [r7]
	ldrb r3, [r2, #7]
	movs r4, #2
	adds r2, r3, #0
	ands r2, r4
	adds r3, r2, #0
	lsls r2, r3, #2
	adds r3, r2, #0
	movs r4, #0x40
	adds r2, r3, #0
	orrs r2, r4
	orrs r1, r2
	ldr r2, [r7]
	ldrb r3, [r2, #7]
	movs r4, #1
	adds r2, r3, #0
	ands r2, r4
	adds r3, r2, #0
	lsls r2, r3, #1
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, _0824C88C @ =0x080000C6
	movs r1, #7
	strh r1, [r0]
	movs r0, #0x62
	bl FUN_0824cc68
	adds r0, r7, #4
	ldrb r1, [r0]
	adds r0, r1, #0
	bl FUN_0824cd0c
	ldr r0, _0824C888 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C888 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C884 @ =0x030026CA
	movs r1, #0
	strb r1, [r0]
	movs r0, #1
	b _0824C890
	.align 2, 0
_0824C884: .4byte 0x030026CA
_0824C888: .4byte 0x080000C4
_0824C88C: .4byte 0x080000C6
_0824C890:
	add sp, #8
	pop {r4, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824c898
FUN_0824c898: @ 0x0824C898
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r0, _0824C8AC @ =0x030026CA
	ldrb r1, [r0]
	cmp r1, #1
	bne _0824C8B0
	movs r0, #0
	b _0824C940
	.align 2, 0
_0824C8AC: .4byte 0x030026CA
_0824C8B0:
	ldr r0, _0824C8E4 @ =0x030026CA
	movs r1, #1
	strb r1, [r0]
	ldr r0, _0824C8E8 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C8E8 @ =0x080000C4
	movs r1, #5
	strh r1, [r0]
	ldr r0, _0824C8EC @ =0x080000C6
	movs r1, #7
	strh r1, [r0]
	movs r0, #0x65
	bl FUN_0824cc68
	ldr r0, _0824C8EC @ =0x080000C6
	movs r1, #5
	strh r1, [r0]
	adds r0, r7, #4
	movs r1, #0
	strb r1, [r0]
_0824C8DA:
	adds r0, r7, #4
	ldrb r1, [r0]
	cmp r1, #6
	bls _0824C8F0
	b _0824C90E
	.align 2, 0
_0824C8E4: .4byte 0x030026CA
_0824C8E8: .4byte 0x080000C4
_0824C8EC: .4byte 0x080000C6
_0824C8F0:
	bl FUN_0824cdac
	adds r1, r7, #4
	ldrb r2, [r1]
	ldr r3, [r7]
	adds r1, r2, r3
	strb r0, [r1]
	adds r1, r7, #4
	adds r0, r7, #4
	adds r1, r7, #4
	ldrb r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strb r2, [r0]
	b _0824C8DA
_0824C90E:
	ldr r1, [r7]
	adds r0, r1, #4
	ldr r2, [r7]
	adds r1, r2, #4
	ldrb r2, [r1]
	movs r3, #0x7f
	adds r1, r2, #0
	ands r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, _0824C938 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C938 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C93C @ =0x030026CA
	movs r1, #0
	strb r1, [r0]
	movs r0, #1
	b _0824C940
	.align 2, 0
_0824C938: .4byte 0x080000C4
_0824C93C: .4byte 0x030026CA
_0824C940:
	add sp, #8
	pop {r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824c948
FUN_0824c948: @ 0x0824C948
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r0, _0824C95C @ =0x030026CA
	ldrb r1, [r0]
	cmp r1, #1
	bne _0824C960
	movs r0, #0
	b _0824C9DC
	.align 2, 0
_0824C95C: .4byte 0x030026CA
_0824C960:
	ldr r0, _0824C990 @ =0x030026CA
	movs r1, #1
	strb r1, [r0]
	ldr r0, _0824C994 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C994 @ =0x080000C4
	movs r1, #5
	strh r1, [r0]
	ldr r0, _0824C998 @ =0x080000C6
	movs r1, #7
	strh r1, [r0]
	movs r0, #0x64
	bl FUN_0824cc68
	adds r0, r7, #4
	movs r1, #0
	strb r1, [r0]
_0824C984:
	adds r0, r7, #4
	ldrb r1, [r0]
	cmp r1, #6
	bls _0824C99C
	b _0824C9BC
	.align 2, 0
_0824C990: .4byte 0x030026CA
_0824C994: .4byte 0x080000C4
_0824C998: .4byte 0x080000C6
_0824C99C:
	adds r0, r7, #4
	ldrb r1, [r0]
	ldr r2, [r7]
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r0, r1, #0
	bl FUN_0824cd0c
	adds r1, r7, #4
	adds r0, r7, #4
	adds r1, r7, #4
	ldrb r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strb r2, [r0]
	b _0824C984
_0824C9BC:
	ldr r0, _0824C9D4 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C9D4 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824C9D8 @ =0x030026CA
	movs r1, #0
	strb r1, [r0]
	movs r0, #1
	b _0824C9DC
	.align 2, 0
_0824C9D4: .4byte 0x080000C4
_0824C9D8: .4byte 0x030026CA
_0824C9DC:
	add sp, #8
	pop {r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824c9e4
FUN_0824c9e4: @ 0x0824C9E4
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r0, _0824C9F8 @ =0x030026CA
	ldrb r1, [r0]
	cmp r1, #1
	bne _0824C9FC
	movs r0, #0
	b _0824CA90
	.align 2, 0
_0824C9F8: .4byte 0x030026CA
_0824C9FC:
	ldr r0, _0824CA30 @ =0x030026CA
	movs r1, #1
	strb r1, [r0]
	ldr r0, _0824CA34 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824CA34 @ =0x080000C4
	movs r1, #5
	strh r1, [r0]
	ldr r0, _0824CA38 @ =0x080000C6
	movs r1, #7
	strh r1, [r0]
	movs r0, #0x67
	bl FUN_0824cc68
	ldr r0, _0824CA38 @ =0x080000C6
	movs r1, #5
	strh r1, [r0]
	adds r0, r7, #4
	movs r1, #0
	strb r1, [r0]
_0824CA26:
	adds r0, r7, #4
	ldrb r1, [r0]
	cmp r1, #2
	bls _0824CA3C
	b _0824CA5C
	.align 2, 0
_0824CA30: .4byte 0x030026CA
_0824CA34: .4byte 0x080000C4
_0824CA38: .4byte 0x080000C6
_0824CA3C:
	bl FUN_0824cdac
	adds r1, r7, #4
	ldrb r2, [r1]
	ldr r3, [r7]
	adds r1, r2, r3
	adds r2, r1, #4
	strb r0, [r2]
	adds r1, r7, #4
	adds r0, r7, #4
	adds r1, r7, #4
	ldrb r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strb r2, [r0]
	b _0824CA26
_0824CA5C:
	ldr r1, [r7]
	adds r0, r1, #4
	ldr r2, [r7]
	adds r1, r2, #4
	ldrb r2, [r1]
	movs r3, #0x7f
	adds r1, r2, #0
	ands r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, _0824CA88 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824CA88 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824CA8C @ =0x030026CA
	movs r1, #0
	strb r1, [r0]
	movs r0, #1
	b _0824CA90
	.align 2, 0
_0824CA88: .4byte 0x080000C4
_0824CA8C: .4byte 0x030026CA
_0824CA90:
	add sp, #8
	pop {r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824ca98
FUN_0824ca98: @ 0x0824CA98
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r0, _0824CAAC @ =0x030026CA
	ldrb r1, [r0]
	cmp r1, #1
	bne _0824CAB0
	movs r0, #0
	b _0824CB2C
	.align 2, 0
_0824CAAC: .4byte 0x030026CA
_0824CAB0:
	ldr r0, _0824CAE0 @ =0x030026CA
	movs r1, #1
	strb r1, [r0]
	ldr r0, _0824CAE4 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824CAE4 @ =0x080000C4
	movs r1, #5
	strh r1, [r0]
	ldr r0, _0824CAE8 @ =0x080000C6
	movs r1, #7
	strh r1, [r0]
	movs r0, #0x66
	bl FUN_0824cc68
	adds r0, r7, #4
	movs r1, #0
	strb r1, [r0]
_0824CAD4:
	adds r0, r7, #4
	ldrb r1, [r0]
	cmp r1, #2
	bls _0824CAEC
	b _0824CB0E
	.align 2, 0
_0824CAE0: .4byte 0x030026CA
_0824CAE4: .4byte 0x080000C4
_0824CAE8: .4byte 0x080000C6
_0824CAEC:
	adds r0, r7, #4
	ldrb r1, [r0]
	ldr r2, [r7]
	adds r0, r1, r2
	adds r1, r0, #4
	ldrb r2, [r1]
	adds r0, r2, #0
	bl FUN_0824cd0c
	adds r1, r7, #4
	adds r0, r7, #4
	adds r1, r7, #4
	ldrb r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strb r2, [r0]
	b _0824CAD4
_0824CB0E:
	ldr r0, _0824CB24 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824CB24 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824CB28 @ =0x030026CA
	movs r1, #0
	strb r1, [r0]
	movs r0, #1
	b _0824CB2C
	.align 2, 0
_0824CB24: .4byte 0x080000C4
_0824CB28: .4byte 0x030026CA
_0824CB2C:
	add sp, #8
	pop {r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824cb34
FUN_0824cb34: @ 0x0824CB34
	push {r4, r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	ldr r0, _0824CB48 @ =0x030026CA
	ldrb r1, [r0]
	cmp r1, #1
	bne _0824CB4C
	movs r0, #0
	b _0824CC60
	.align 2, 0
_0824CB48: .4byte 0x030026CA
_0824CB4C:
	ldr r0, _0824CBB4 @ =0x030026CA
	movs r1, #1
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #8
	ldr r1, [r7]
	ldrb r2, [r1, #8]
	movs r3, #0xf
	adds r1, r2, #0
	ands r1, r3
	ldr r2, [r7]
	ldrb r3, [r2, #8]
	lsrs r2, r3, #4
	adds r3, r2, #0
	movs r4, #0xf
	adds r2, r3, #0
	ands r2, r4
	adds r4, r2, #0
	lsls r3, r4, #0x18
	lsrs r2, r3, #0x18
	adds r4, r2, #0
	lsls r3, r4, #2
	adds r3, r3, r2
	lsls r2, r3, #1
	adds r1, r1, r2
	ldrb r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #8
	ldrb r1, [r0]
	cmp r1, #0xb
	bhi _0824CBB8
	adds r0, r7, #0
	adds r0, #8
	ldr r1, [r7]
	ldrb r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrb r1, [r1, #8]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0]
	b _0824CBD6
	.align 2, 0
_0824CBB4: .4byte 0x030026CA
_0824CBB8:
	adds r0, r7, #0
	adds r0, #8
	ldr r1, [r7]
	ldrb r2, [r1, #8]
	movs r3, #0x80
	adds r1, r2, #0
	orrs r1, r3
	ldrb r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0]
_0824CBD6:
	adds r0, r7, #0
	adds r0, #8
	ldr r1, [r7]
	ldrb r2, [r0, #1]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrb r1, [r1, #9]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0, #1]
	ldr r0, _0824CC18 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824CC18 @ =0x080000C4
	movs r1, #5
	strh r1, [r0]
	ldr r0, _0824CC1C @ =0x080000C6
	movs r1, #7
	strh r1, [r0]
	movs r0, #0x68
	bl FUN_0824cc68
	adds r0, r7, #4
	movs r1, #0
	strb r1, [r0]
_0824CC0C:
	adds r0, r7, #4
	ldrb r1, [r0]
	cmp r1, #1
	bls _0824CC20
	b _0824CC42
	.align 2, 0
_0824CC18: .4byte 0x080000C4
_0824CC1C: .4byte 0x080000C6
_0824CC20:
	adds r0, r7, #0
	adds r0, #8
	adds r1, r7, #4
	ldrb r2, [r1]
	adds r0, r0, r2
	ldrb r1, [r0]
	adds r0, r1, #0
	bl FUN_0824cd0c
	adds r1, r7, #4
	adds r0, r7, #4
	adds r1, r7, #4
	ldrb r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strb r2, [r0]
	b _0824CC0C
_0824CC42:
	ldr r0, _0824CC58 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824CC58 @ =0x080000C4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0824CC5C @ =0x030026CA
	movs r1, #0
	strb r1, [r0]
	movs r0, #1
	b _0824CC60
	.align 2, 0
_0824CC58: .4byte 0x080000C4
_0824CC5C: .4byte 0x030026CA
_0824CC60:
	add sp, #0xc
	pop {r4, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824cc68
FUN_0824cc68: @ 0x0824CC68
	push {r4, r5, r7, lr}
	sub sp, #4
	mov r7, sp
	adds r1, r0, #0
	adds r2, r7, #0
	strb r1, [r2]
	adds r1, r7, #1
	movs r2, #0
	strb r2, [r1]
_0824CC7A:
	adds r1, r7, #1
	ldrb r2, [r1]
	cmp r2, #7
	bls _0824CC84
	b _0824CD04
_0824CC84:
	adds r1, r7, #2
	adds r3, r7, #0
	ldrb r2, [r3]
	adds r3, r7, #1
	ldrb r4, [r3]
	movs r5, #7
	subs r3, r5, r4
	asrs r2, r3
	adds r3, r2, #0
	movs r4, #1
	adds r2, r3, #0
	ands r2, r4
	adds r3, r2, #0
	strb r3, [r1]
	ldr r1, _0824CD00 @ =0x080000C4
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #4
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	ldr r1, _0824CD00 @ =0x080000C4
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #4
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	ldr r1, _0824CD00 @ =0x080000C4
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #4
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	ldr r1, _0824CD00 @ =0x080000C4
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #5
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	adds r2, r7, #1
	adds r1, r7, #1
	adds r2, r7, #1
	ldrb r3, [r2]
	adds r2, r3, #1
	adds r3, r2, #0
	strb r3, [r1]
	b _0824CC7A
	.align 2, 0
_0824CD00: .4byte 0x080000C4
_0824CD04:
	add sp, #4
	pop {r4, r5, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824cd0c
FUN_0824cd0c: @ 0x0824CD0C
	push {r4, r7, lr}
	sub sp, #4
	mov r7, sp
	adds r1, r0, #0
	adds r2, r7, #0
	strb r1, [r2]
	adds r1, r7, #1
	movs r2, #0
	strb r2, [r1]
_0824CD1E:
	adds r1, r7, #1
	ldrb r2, [r1]
	cmp r2, #7
	bls _0824CD28
	b _0824CDA4
_0824CD28:
	adds r1, r7, #2
	adds r3, r7, #0
	ldrb r2, [r3]
	adds r3, r7, #1
	ldrb r4, [r3]
	asrs r2, r4
	adds r3, r2, #0
	movs r4, #1
	adds r2, r3, #0
	ands r2, r4
	adds r3, r2, #0
	strb r3, [r1]
	ldr r1, _0824CDA0 @ =0x080000C4
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #4
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	ldr r1, _0824CDA0 @ =0x080000C4
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #4
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	ldr r1, _0824CDA0 @ =0x080000C4
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #4
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	ldr r1, _0824CDA0 @ =0x080000C4
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #5
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	adds r2, r7, #1
	adds r1, r7, #1
	adds r2, r7, #1
	ldrb r3, [r2]
	adds r2, r3, #1
	adds r3, r2, #0
	strb r3, [r1]
	b _0824CD1E
	.align 2, 0
_0824CDA0: .4byte 0x080000C4
_0824CDA4:
	add sp, #4
	pop {r4, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824cdac
FUN_0824cdac: @ 0x0824CDAC
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	adds r0, r7, #0
	movs r1, #0
	strb r1, [r0]
_0824CDB8:
	adds r0, r7, #0
	ldrb r1, [r0]
	cmp r1, #7
	bls _0824CDC2
	b _0824CE28
_0824CDC2:
	ldr r0, _0824CE24 @ =0x080000C4
	movs r1, #4
	strh r1, [r0]
	ldr r0, _0824CE24 @ =0x080000C4
	movs r1, #4
	strh r1, [r0]
	ldr r0, _0824CE24 @ =0x080000C4
	movs r1, #4
	strh r1, [r0]
	ldr r0, _0824CE24 @ =0x080000C4
	movs r1, #4
	strh r1, [r0]
	ldr r0, _0824CE24 @ =0x080000C4
	movs r1, #4
	strh r1, [r0]
	ldr r0, _0824CE24 @ =0x080000C4
	movs r1, #5
	strh r1, [r0]
	adds r0, r7, #1
	ldr r1, _0824CE24 @ =0x080000C4
	ldrh r2, [r1]
	movs r3, #2
	adds r1, r2, #0
	ands r1, r3
	adds r3, r1, #0
	lsls r2, r3, #0x10
	lsrs r1, r2, #0x10
	lsrs r2, r1, #1
	adds r1, r2, #0
	strb r1, [r0]
	adds r0, r7, #2
	adds r1, r7, #2
	ldrb r2, [r1]
	lsrs r1, r2, #1
	adds r2, r7, #1
	ldrb r3, [r2]
	lsls r2, r3, #7
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	adds r1, r7, #0
	adds r0, r7, #0
	adds r1, r7, #0
	ldrb r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strb r2, [r0]
	b _0824CDB8
	.align 2, 0
_0824CE24: .4byte 0x080000C4
_0824CE28:
	adds r0, r7, #2
	ldrb r1, [r0]
	adds r0, r1, #0
	b _0824CE30
_0824CE30:
	add sp, #4
	pop {r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824ce38
FUN_0824ce38: @ 0x0824CE38
	push {r7, lr}
	mov r7, sp
	ldr r0, _0824CE48 @ =0x080000C8
	movs r1, #1
	strh r1, [r0]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824CE48: .4byte 0x080000C8

	thumb_func_start FUN_0824ce4c
FUN_0824ce4c: @ 0x0824CE4C
	push {r7, lr}
	mov r7, sp
	ldr r0, _0824CE5C @ =0x080000C8
	movs r1, #0
	strh r1, [r0]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824CE5C: .4byte 0x080000C8

