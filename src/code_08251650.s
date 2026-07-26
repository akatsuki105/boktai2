.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start FUN_08251650
FUN_08251650: @ 0x08251650
	adds r3, r0, #0
	movs r1, #0
	ldr r2, _08251658 @ =0x03002708
	b _08251664
	.align 2, 0
_08251658: .4byte 0x03002708
_0825165C:
	adds r2, #8
	adds r1, #1
	cmp r1, #0x13
	bgt _0825166A
_08251664:
	ldr r0, [r2]
	cmp r0, r3
	bne _0825165C
_0825166A:
	adds r0, r1, #0
	bx lr
	.align 2, 0

	thumb_func_start FUN_08251670
FUN_08251670: @ 0x08251670
	adds r2, r0, #0
	ldr r0, _08251684 @ =0x08DBDDD4
	ldr r1, [r0]
	ldr r0, [r1, #4]
	movs r3, #0xe
	ldrsh r0, [r0, r3]
	cmp r2, r0
	bne _0825168C
	ldr r0, _08251688 @ =0x030026FC
	b _082516B2
	.align 2, 0
_08251684: .4byte 0x08DBDDD4
_08251688: .4byte 0x030026FC
_0825168C:
	ldr r0, [r1, #8]
	movs r3, #0xe
	ldrsh r0, [r0, r3]
	cmp r2, r0
	bne _082516A0
	ldr r0, _0825169C @ =0x03002700
	b _082516B2
	.align 2, 0
_0825169C: .4byte 0x03002700
_082516A0:
	ldr r0, [r1, #0xc]
	movs r1, #0xe
	ldrsh r0, [r0, r1]
	cmp r2, r0
	beq _082516B0
	adds r0, r2, #0
	subs r0, #0x20
	b _082516B4
_082516B0:
	ldr r0, _082516B8 @ =0x03002704
_082516B2:
	ldr r0, [r0]
_082516B4:
	bx lr
	.align 2, 0
_082516B8: .4byte 0x03002704

	thumb_func_start FUN_082516bc
FUN_082516bc: @ 0x082516BC
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, _08251718 @ =0x085A90E0
	str r4, [sp]
	movs r3, #3
	str r3, [sp, #8]
	movs r0, #0
	str r0, [sp, #4]
	movs r5, #1
	adds r0, r5, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	ldr r5, _0825171C @ =0x030026FC
	str r2, [r5]
	str r4, [sp]
	str r3, [sp, #8]
	movs r0, #4
	str r0, [sp, #4]
	ldr r3, _08251720 @ =0x03002700
	movs r4, #1
	adds r0, r4, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	ldr r0, _08251724 @ =0x03002704
	str r2, [r0]
	str r2, [r3]
	ldr r2, _08251728 @ =0x03002708
	adds r1, r2, #0
	subs r4, #2
	adds r0, r2, #0
	adds r0, #0x98
_082516FE:
	str r4, [r0]
	subs r0, #8
	cmp r0, r1
	bge _082516FE
	movs r0, #0
	ldr r1, [r5]
	str r1, [r2]
	str r0, [r2, #4]
	ldr r1, [r3]
	str r1, [r2, #8]
	str r0, [r2, #0xc]
	add sp, #0xc
	pop {r4, r5, pc}
	.align 2, 0
_08251718: .4byte 0x085A90E0
_0825171C: .4byte 0x030026FC
_08251720: .4byte 0x03002700
_08251724: .4byte 0x03002704
_08251728: .4byte 0x03002708

	thumb_func_start FUN_0825172c
FUN_0825172c: @ 0x0825172C
	push {r4, lr}
	movs r3, #0x13
	movs r4, #0
	adds r0, r3, #0
	adds r1, r4, #0
	svc #0xab
	adds r2, r0, #0
	adds r0, r2, #0
	pop {r4, pc}
	.align 2, 0

	thumb_func_start FUN_08251740
FUN_08251740: @ 0x08251740
	push {r4, r5, lr}
	adds r5, r0, #0
	bl __errno
	adds r4, r0, #0
	bl FUN_0825172c
	str r0, [r4]
	adds r0, r5, #0
	pop {r4, r5, pc}

	thumb_func_start FUN_08251754
FUN_08251754: @ 0x08251754
	push {lr}
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08251764
	adds r0, r1, #0
	b _0825176A
_08251764:
	adds r0, r1, #0
	bl FUN_08251740
_0825176A:
	pop {pc}

	thumb_func_start FUN_0825176c
FUN_0825176c: @ 0x0825176C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r1, #0
	adds r5, r2, #0
	bl FUN_08251670
	str r0, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r3, #6
	adds r0, r3, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	adds r0, r2, #0
	add sp, #0xc
	pop {r4, r5, pc}
	.align 2, 0

	thumb_func_start FUN_08251790
FUN_08251790: @ 0x08251790
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	bl FUN_08251670
	bl FUN_08251650
	adds r6, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl FUN_0825176c
	cmp r0, #0
	bge _082517BA
	movs r0, #1
	rsbs r0, r0, #0
	bl FUN_08251740
	b _082517D0
_082517BA:
	subs r2, r7, r0
	cmp r6, #0x14
	beq _082517CE
	ldr r0, _082517D4 @ =0x03002708
	lsls r1, r6, #3
	adds r0, #4
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
_082517CE:
	adds r0, r2, #0
_082517D0:
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_082517D4: .4byte 0x03002708

	thumb_func_start FUN_082517d8
FUN_082517d8: @ 0x082517D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r5, r1, #0
	adds r4, r2, #0
	bl FUN_08251670
	adds r7, r0, #0
	bl FUN_08251650
	adds r6, r0, #0
	cmp r4, #1
	bne _0825180E
	cmp r6, #0x14
	bne _08251800
	movs r0, #1
	rsbs r0, r0, #0
	b _08251850
_08251800:
	ldr r0, _08251858 @ =0x03002708
	lsls r1, r6, #3
	adds r0, #4
	adds r1, r1, r0
	ldr r0, [r1]
	adds r5, r5, r0
	movs r4, #0
_0825180E:
	cmp r4, #2
	bne _08251820
	str r7, [sp]
	movs r3, #0xc
	adds r0, r3, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	adds r5, r5, r2
_08251820:
	mov r0, r8
	bl FUN_08251670
	str r0, [sp]
	str r5, [sp, #4]
	movs r3, #0xa
	adds r0, r3, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	cmp r6, #0x14
	beq _08251846
	cmp r2, #0
	bne _08251846
	ldr r0, _08251858 @ =0x03002708
	lsls r1, r6, #3
	adds r0, #4
	adds r1, r1, r0
	str r5, [r1]
_08251846:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, #0
	bne _08251850
	adds r0, r5, #0
_08251850:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08251858: .4byte 0x03002708
_0825185C:
	.byte 0x00, 0xB5, 0xFF, 0xF7
	.byte 0xBB, 0xFF, 0xFF, 0xF7, 0x77, 0xFF, 0x00, 0xBD

	thumb_func_start FUN_08251868
FUN_08251868: @ 0x08251868
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r1, #0
	adds r5, r2, #0
	bl FUN_08251670
	str r0, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r3, #5
	adds r0, r3, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	adds r0, r2, #0
	add sp, #0xc
	pop {r4, r5, pc}
	.align 2, 0

	thumb_func_start FUN_0825188c
FUN_0825188c: @ 0x0825188C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	bl FUN_08251670
	bl FUN_08251650
	adds r7, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08251868
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _082518B4
	cmp r0, r6
	bne _082518BC
_082518B4:
	adds r0, r1, #0
	bl FUN_08251740
	b _082518D2
_082518BC:
	subs r2, r6, r0
	cmp r7, #0x14
	beq _082518D0
	ldr r0, _082518D4 @ =0x03002708
	lsls r1, r7, #3
	adds r0, #4
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
_082518D0:
	adds r0, r2, #0
_082518D2:
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_082518D4: .4byte 0x03002708

	thumb_func_start FUN_082518d8
FUN_082518d8: @ 0x082518D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	adds r4, r1, #0
	movs r5, #0
	movs r6, #1
	rsbs r6, r6, #0
	adds r0, r6, #0
	bl FUN_08251650
	mov r8, r0
	cmp r0, #0x14
	bne _082518FA
	adds r0, r6, #0
	b _0825196E
_082518FA:
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq _08251904
	movs r5, #2
_08251904:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _08251912
	movs r0, #4
	orrs r5, r0
_08251912:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	beq _08251920
	movs r0, #4
	orrs r5, r0
_08251920:
	movs r1, #8
	ands r4, r1
	cmp r4, #0
	beq _08251930
	movs r0, #5
	rsbs r0, r0, #0
	ands r5, r0
	orrs r5, r1
_08251930:
	str r7, [sp]
	adds r0, r7, #0
	bl strlen
	str r0, [sp, #8]
	str r5, [sp, #4]
	movs r2, #1
	adds r0, r2, #0
	mov r1, sp
	svc #0xab
	adds r3, r0, #0
	cmp r3, #0
	blt _08251968
	ldr r0, _08251964 @ =0x03002708
	mov r1, r8
	lsls r2, r1, #3
	adds r1, r2, r0
	str r3, [r1]
	adds r0, #4
	adds r2, r2, r0
	movs r0, #0
	str r0, [r2]
	adds r0, r3, #0
	adds r0, #0x20
	b _0825196E
	.align 2, 0
_08251964: .4byte 0x03002708
_08251968:
	adds r0, r3, #0
	bl FUN_08251740
_0825196E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08251978:
	.byte 0x0E, 0xB4, 0x00, 0xB5, 0x01, 0x99, 0xFF, 0xF7
	.byte 0xAB, 0xFF, 0xFF, 0xF7, 0xE7, 0xFE, 0x08, 0xBC, 0x03, 0xB0, 0x18, 0x47

	thumb_func_start FUN_0825198c
FUN_0825198c: @ 0x0825198C
	push {lr}
	sub sp, #4
	bl FUN_08251670
	str r0, [sp]
	bl FUN_08251650
	adds r1, r0, #0
	cmp r1, #0x14
	beq _082519AC
	ldr r0, _082519BC @ =0x03002708
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
_082519AC:
	movs r3, #2
	adds r0, r3, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	adds r0, r2, #0
	add sp, #4
	pop {pc}
	.align 2, 0
_082519BC: .4byte 0x03002708
_082519C0:
	.byte 0x00, 0xB5, 0xFF, 0xF7, 0xE3, 0xFF, 0xFF, 0xF7, 0xC5, 0xFE, 0x00, 0xBD
	thumb_func_start _exit
_exit:
	mov ip, r3
	mov r3, r8
	push {r3}
	mov r3, ip
	movs r2, #0x18
	ldr r3, _082519E8 @ =0x00020026
	adds r0, r2, #0
	adds r1, r3, #0
	svc #0xab
	mov r8, r0
	pop {r3}
	mov r8, r3
	bx lr
	.align 2, 0
_082519E8: .4byte 0x00020026
_082519EC:
	.byte 0x9C, 0x46, 0x43, 0x46

	thumb_func_start FUN_082519f0
FUN_082519f0: @ 0x082519F0
	push {r3}
	mov r3, ip
	movs r2, #0x18
	ldr r3, _08251A08 @ =0x00020026
	adds r0, r2, #0
	adds r1, r3, #0
	svc #0xab
	mov r8, r0
	pop {r3}
	mov r8, r3
	bx lr
	.align 2, 0
_08251A08: .4byte 0x00020026

	thumb_func_start FUN_08251a0c
FUN_08251a0c: @ 0x08251A0C
	movs r0, #1
	bx lr

	thumb_func_start FUN_08251a10
FUN_08251a10: @ 0x08251A10
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, _08251A40 @ =0x030026F8
	ldr r0, [r4]
	cmp r0, #0
	bne _08251A20
	ldr r0, _08251A44 @ =0x03005820
	str r0, [r4]
_08251A20:
	ldr r5, [r4]
	adds r0, r5, r6
	cmp r0, sp
	bls _08251A36
	ldr r1, _08251A48 @ =0x085A90E4
	movs r0, #1
	movs r2, #0x20
	bl FUN_0825188c
	bl abort
_08251A36:
	ldr r0, [r4]
	adds r0, r0, r6
	str r0, [r4]
	adds r0, r5, #0
	pop {r4, r5, r6, pc}
	.align 2, 0
_08251A40: .4byte 0x030026F8
_08251A44: .4byte 0x03005820
_08251A48: .4byte 0x085A90E4
_08251A4C:
	.byte 0x80, 0x20, 0x80, 0x01
	.byte 0x48, 0x60, 0x00, 0x20, 0x70, 0x47, 0x00, 0x00, 0x01, 0x20, 0x40, 0x42, 0x70, 0x47, 0x00, 0x00
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_08251a64
FUN_08251a64: @ 0x08251A64
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	cmp r2, #0
	beq _08251A82
	movs r4, #0x11
	movs r5, #0
	adds r0, r4, #0
	adds r1, r5, #0
	svc #0xab
	adds r5, r0, #0
	adds r4, r5, #0
	str r4, [r2]
	movs r0, #0
	str r0, [r2, #4]
_08251A82:
	cmp r3, #0
	beq _08251A8C
	movs r0, #0
	str r0, [r3]
	str r0, [r3, #4]
_08251A8C:
	movs r0, #0
	pop {r4, r5, pc}

	thumb_func_start FUN_08251a90
FUN_08251a90: @ 0x08251A90
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r4, #0x10
	movs r5, #0
	adds r0, r4, #0
	adds r1, r5, #0
	svc #0xab
	adds r3, r0, #0
	cmp r2, #0
	beq _08251AAE
	str r3, [r2]
	movs r0, #0
	str r0, [r2, #4]
	str r0, [r2, #8]
	str r0, [r2, #0xc]
_08251AAE:
	adds r0, r3, #0
	pop {r4, r5, pc}
	.align 2, 0

