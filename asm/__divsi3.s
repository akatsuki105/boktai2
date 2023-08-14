	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start __divsi3
__divsi3: @ 0x0824CE9C
	cmp r1, #0
	beq _0824CF24
	push {r4}
	adds r4, r0, #0
	eors r4, r1
	mov ip, r4
	movs r3, #1
	movs r2, #0
	cmp r1, #0
	bpl _0824CEB2
	rsbs r1, r1, #0
_0824CEB2:
	cmp r0, #0
	bpl _0824CEB8
	rsbs r0, r0, #0
_0824CEB8:
	cmp r0, r1
	blo _0824CF16
	movs r4, #1
	lsls r4, r4, #0x1c
_0824CEC0:
	cmp r1, r4
	bhs _0824CECE
	cmp r1, r0
	bhs _0824CECE
	lsls r1, r1, #4
	lsls r3, r3, #4
	b _0824CEC0
_0824CECE:
	lsls r4, r4, #3
_0824CED0:
	cmp r1, r4
	bhs _0824CEDE
	cmp r1, r0
	bhs _0824CEDE
	lsls r1, r1, #1
	lsls r3, r3, #1
	b _0824CED0
_0824CEDE:
	cmp r0, r1
	blo _0824CEE6
	subs r0, r0, r1
	orrs r2, r3
_0824CEE6:
	lsrs r4, r1, #1
	cmp r0, r4
	blo _0824CEF2
	subs r0, r0, r4
	lsrs r4, r3, #1
	orrs r2, r4
_0824CEF2:
	lsrs r4, r1, #2
	cmp r0, r4
	blo _0824CEFE
	subs r0, r0, r4
	lsrs r4, r3, #2
	orrs r2, r4
_0824CEFE:
	lsrs r4, r1, #3
	cmp r0, r4
	blo _0824CF0A
	subs r0, r0, r4
	lsrs r4, r3, #3
	orrs r2, r4
_0824CF0A:
	cmp r0, #0
	beq _0824CF16
	lsrs r3, r3, #4
	beq _0824CF16
	lsrs r1, r1, #4
	b _0824CEDE
_0824CF16:
	adds r0, r2, #0
	mov r4, ip
	cmp r4, #0
	bpl _0824CF20
	rsbs r0, r0, #0
_0824CF20:
	pop {r4}
	mov pc, lr
_0824CF24:
	push {lr}
	bl FUN_0824cf30
	movs r0, #0
	pop {pc}
	.align 2, 0
